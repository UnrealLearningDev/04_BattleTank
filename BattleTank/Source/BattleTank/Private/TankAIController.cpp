// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cannot find Player Controller"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player controller at tank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	else
	{
		return  Cast<ATank>(PlayerPawn);
	}
}

