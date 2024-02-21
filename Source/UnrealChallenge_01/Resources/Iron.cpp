// Fill out your copyright notice in the Description page of Project Settings.


#include "Iron.h"

// Sets default values
AIron::AIron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set up box range
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// Called when the game starts or when spawned
void AIron::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AIron::Loop, SpawnDelay, true);
}

// Called every frame
void AIron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIron::Loop()
{
	if (ShouldSpawn)
	{
		SpawnActor();

		i++;
		if (i == 3)
		{
			Range();
		}
	}
}

void AIron::Range()
{
	ShouldSpawn = false;
}

bool AIron::SpawnActor()
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