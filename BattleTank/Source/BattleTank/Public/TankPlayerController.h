// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include"Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	//start the tank moving the barrell so a shot hits where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
  