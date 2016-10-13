// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"	 
#include "TankAimingComponent.h"
#include "TankAIController.h"


void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();
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

	AimingComponent->Fire();	 //TODO limit firing rate
}

