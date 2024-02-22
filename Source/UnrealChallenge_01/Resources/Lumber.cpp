// Fill out your copyright notice in the Description page of Project Settings.


#include "Lumber.h"

// Sets default values
ALumber::ALumber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// Called when the game starts or when spawned
void ALumber::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ALumber::Loop, SpawnDelay, true);
}

// Called every frame
void ALumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALumber::Loop()
{
	if (ShouldSpawn)
	{
		SpawnActor();
	}
}

void ALumber::Stop()
{
	if (range >= 3)
		ShouldSpawn = false;
}

bool ALumber::SpawnActor()
{
	bool SpawnedActor = false;

	if (ActorClassToBeSpawned)
	{
		//Calculate boundary of the box
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		//Spawn Location at origin
		FVector SpawnLocation = BoxBounds.Origin;

		SpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &SpawnLocation) != nullptr;
	}

	return SpawnedActor;
}