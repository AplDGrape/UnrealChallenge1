// Fill out your copyright notice in the Description page of Project Settings.


#include "Furnace.h"

// Sets default values
AFurnace::AFurnace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// Called when the game starts or when spawned
void AFurnace::BeginPlay()
{
	Super::BeginPlay();
	
	/*if (ShouldSpawn)
	{
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AFurnace::Loop, SpawnDelay, true);
	}*/
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFurnace::Start()
{
	ShouldSpawn = true;

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AFurnace::Loop, SpawnDelay, true);

	Stop();
}

void AFurnace::Loop()
{
	if (ShouldSpawn)
	{
		SpawnActor();
	}
}

void AFurnace::Stop()
{
	if (range >= 4)
		ShouldSpawn = false;
}

bool AFurnace::SpawnActor()
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