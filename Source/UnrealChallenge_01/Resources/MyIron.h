// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Iron.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerBox.h"
#include "MyIron.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGE_01_API AMyIron : public AIron
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay();

public:
	AMyIron();

	int i = 0;

	UFUNCTION()
	void Event(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere)
	AActor* ball;
};
