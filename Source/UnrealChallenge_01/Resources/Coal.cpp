// Fill out your copyright notice in the Description page of Project Settings.


#include "Coal.h"

// Sets default values
ACoal::ACoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// Called when the game starts or when spawned
void ACoal::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ACoal::Loop, SpawnDelay, true);
}

// Called every frame
void ACoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoal::Loop()
{
	if (ShouldSpawn)
	{
		SpawnActor();
	}
}

void ACoal::Stop()
{
	if (range >= 3)
		ShouldSpawn = false;
}

bool ACoal::SpawnActor()
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