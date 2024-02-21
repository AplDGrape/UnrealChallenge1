// Fill out your copyright notice in the Description page of Project Settings.


#include "MyIron.h"

AMyIron::AMyIron()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyIron::Event);
}

void AMyIron::BeginPlay()
{
	Super::BeginPlay();
}

void AMyIron::Event(class AActor* overlappedActor, class AActor* otherActor)
{
	AIron* MyChar = Cast<AIron>(ActorClassToBeSpawned);

	while (i <= 3)
	{
		if (otherActor && otherActor != this)
		{
			if (MyChar)
			{
				i++;
			}
		}
	}
}