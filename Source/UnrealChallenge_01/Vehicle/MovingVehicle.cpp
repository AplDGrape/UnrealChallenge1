// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingVehicle.h"

#include "Components/BoxComponent.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
AMovingVehicle::AMovingVehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = BoxCollider;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("MovementComponent"));

	MovementComponent->Duration = CurSpeed;
	MovementComponent->bSweep = true;
	MovementComponent->BehaviourType = EInterpToBehaviourType::Loop_Reset;
}

// Called when the game starts or when spawned
void AMovingVehicle::BeginPlay()
{
	Super::BeginPlay();

	MovementComponent->ControlPoints.Add(FInterpControlPoint(FVector(0.f, 0.f, 0.f), true));

	for (int i = 0; i < ThePath.Num(); i++)
	{
		MovementComponent->ControlPoints.Add(FInterpControlPoint(ThePath[i], true));

		if (ThePath.Num() == 2)
		{
			SpawnActor();
		}
	}

	MovementComponent->FinaliseControlPoints();
}

// Called every frame
void AMovingVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AMovingVehicle::SpawnActor()
{
	bool SpawnedActor = false;

	if (Iron)
	{
		FBoxSphereBounds BoxBounds = BoxCollider->CalcBounds(GetActorTransform());

		FVector SpawnLocation = BoxBounds.Origin;

		SpawnedActor = GetWorld()->SpawnActor(Iron, &SpawnLocation) != nullptr;
	}
	return SpawnedActor;
}