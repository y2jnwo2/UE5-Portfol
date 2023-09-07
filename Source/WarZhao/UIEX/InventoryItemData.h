// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <GlobalGameInstance/Data/ItemData.h>
#include "InventoryItemData.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UInventoryItemData : public UObject
{
	GENERATED_BODY()

public:
	class UInventoryItemSlot* Widget;
	int Index = 0;
	int Count = 1;
	const FItemData* Data;
};
