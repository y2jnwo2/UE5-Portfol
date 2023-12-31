// Fill out your copyright notice in the Description page of Project Settings.


#include "UIEX/MiniMapActor.h"

// Sets default values
AMiniMapActor::AMiniMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMiniMapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMiniMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr == TraceActor)
	{
		return;
	}

	SetActorLocation(TraceActor->GetActorLocation());
}

