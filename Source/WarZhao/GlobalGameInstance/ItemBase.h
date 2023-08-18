// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GlobalGameInstance/Data/ItemData.h>
#include "ItemBase.generated.h"

UCLASS()
class WARZHAO_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	//UFUNCTION(BlueprintCallable)
	//void Take(AActor* _Actor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:	
	// Called every frame
	const struct FItemData* Data = nullptr;
};
