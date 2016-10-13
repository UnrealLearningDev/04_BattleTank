// CopyRight EmbraceIT Ltd.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	//Needed for the BP BeginPLay to run!!!!!
	//UE_LOG(LogTemp, Warning, TEXT("DONKEY: BeginPLay C++"));
}

					  