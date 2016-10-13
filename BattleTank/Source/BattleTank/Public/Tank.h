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

private:
	// Sets default values for this pawn's properties
	ATank();
																							  

};
