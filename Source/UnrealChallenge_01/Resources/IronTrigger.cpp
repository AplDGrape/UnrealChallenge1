// Fill out your copyright notice in the Description page of Project Settings.


#include "IronTrigger.h"

AIronTrigger::AIronTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AIronTrigger::Event);
}

void AIronTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void AIronTrigger::Event(class AActor* overlappedActor, class AActor* otherActor)
{
	
}