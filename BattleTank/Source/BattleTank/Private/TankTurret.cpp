// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeRotateSpeed)
{
	RelativeRotateSpeed = FMath::Clamp<float>(RelativeRotateSpeed, -1, 1);
	auto ElevationChange = RelativeRotateSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Roll + ElevationChange;
	SetRelativeRotation(FRotator(RawNewRotation, 0, 0));
}

