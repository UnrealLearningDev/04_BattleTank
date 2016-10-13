// CopyRight EmbraceIT Ltd.

 #pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put new includes above

//Forward declarations
class UTankBarrel;//Forward declaration
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();
																							  
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//TODO remove firing
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	//TODO remove
	UTankBarrel* Barrel = nullptr;//local barrel refernce for spawnig projectile

	double LastFireTime = 0;
};
