// CopyRight EmbraceIT Ltd.

 #pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put new includes above

//Forward declarations
class UTankAimingComponent;
class UTankBarrel;//Forward declaration
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	void AimAt(FVector HitLocation);

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();
																							  
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	//TODO remove
	UTankBarrel* Barrel = nullptr;//local barrel refernce for spawnig projectile

	double LastFireTime = 0;
};
