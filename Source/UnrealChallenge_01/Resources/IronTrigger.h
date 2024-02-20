// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Iron.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerBox.h"
#include "IronTrigger.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGE_01_API AIronTrigger : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay();

public:
	AIronTrigger();

	//UPROPERTY()
	//AIron* ShouldSpawn;

	UFUNCTION()
	void Event(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere)
	AActor* ball;
};
