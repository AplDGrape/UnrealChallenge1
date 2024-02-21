// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Iron.generated.h"

UCLASS()
class UNREALCHALLENGE_01_API AIron : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIron();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnDelay = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	int i = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Spawn an actor
	UFUNCTION(BlueprintCallable) bool SpawnActor();
	
	UFUNCTION(BlueprintCallable) void Loop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool ShouldSpawn = true;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	//Looping
	UFUNCTION(BlueprintCallable) void Range();

	//Returns the WhereToSPawn subobject
	//FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn;  }

private:

	//Box size to spawn actor
	UPROPERTY(EditDefaultsOnly) UBoxComponent* SpawnBox;

	//Specify where pick ups should spawn
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	//class UBoxComponent* WhereToSpawn;
};
