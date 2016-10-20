// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"	 
#include "TankAimingComponent.h"
#include "Tank.h"//so we cna implement OnDeath 
#include "TankAIController.h"


void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure (PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event

	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius );//TODO check radius is in centimeters

	//aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();	 //TODO limit firing rate
	}
}

