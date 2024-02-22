// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Furnace.generated.h"

UCLASS()
class UNREALCHALLENGE_01_API AFurnace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFurnace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnDelay = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	int range = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable) bool SpawnActor();

	UFUNCTION(BlueprintCallable) void Loop();

	UFUNCTION(BlueprintCallable) void Start();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool ShouldSpawn = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	UFUNCTION(BlueprintCallable) void Stop();

private:
	UPROPERTY(EditDefaultsOnly) UBoxComponent* SpawnBox;
};
