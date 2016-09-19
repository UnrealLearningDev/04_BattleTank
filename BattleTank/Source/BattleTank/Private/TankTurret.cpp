// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeRotateSpeed)
{
	RelativeRotateSpeed = FMath::Clamp<float>(RelativeRotateSpeed, -1, 1);
	auto RotationChange = RelativeRotateSpeed*MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

