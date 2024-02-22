// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"

#include "MovingVehicle.generated.h"

UCLASS()
class UNREALCHALLENGE_01_API AMovingVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Vehicle pathing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	TArray<FVector> ThePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathing", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true"))
	float CurSpeed = 25;

	//Spawning items
	UFUNCTION(BlueprintCallable) bool SpawnActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool ShouldSpawn = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Iron;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* MyMesh;

	//deals movement
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UInterpToMovementComponent* MovementComponent;
};
