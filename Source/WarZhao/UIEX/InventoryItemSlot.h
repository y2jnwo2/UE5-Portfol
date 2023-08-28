// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <GlobalGameInstance/Data/ItemData.h>
#include <UIEX/InventoryItemData.h>
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "InventoryItemSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlotFunction);

/**
 * 
 */
UCLASS()
class WARZHAO_API UInventoryItemSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite)
	ESlateVisibility ItemBackVisibility = ESlateVisibility::Visible;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite)
	ESlateVisibility ItemIconVisibility = ESlateVisibility::Hidden;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite)
	ESlateVisibility ItemCountVisibility = ESlateVisibility::Hidden;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite)
	ItemType ItemTypeValue = ItemType::NONE;

	UPROPERTY(Category = "Icon", EditAnywhere, BlueprintReadWrite)
	UImage* ItemIconImage = nullptr;

	UPROPERTY(Category = "Icon", EditAnywhere, BlueprintReadWrite)
	UImage* ItemIconBack = nullptr;

	UPROPERTY(Category = "Count", EditAnywhere, BlueprintReadWrite)
	UTextBlock* ItemCountBlock = nullptr;

	UPROPERTY(Category = "Count", EditAnywhere, BlueprintReadWrite)
	int ItemCountValue = 0;

	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	FORCEINLINE UInventoryItemData* GetItemDataObject()
	{
		return ItemData;
	}

	void SetItemData(UInventoryItemData* _ItemData);

	void SlotDataCheck();

	UFUNCTION(BlueprintCallable)
	void DragSetting(UInventoryItemSlot* _OtherDragSlot);

	UFUNCTION(BlueprintCallable)
	void MoveSetting(UInventoryItemSlot* _OtherDragSlot);

	UFUNCTION(BlueprintCallable)
	bool IsEmpty()
	{
		return ItemData->Data == nullptr;
	}

	UPROPERTY(BlueprintAssignable, visibleAnywhere, BlueprintCallable)
	FSlotFunction ItemChangeFunction;

	UFUNCTION(BluePrintCallable)
	UInventoryItemData* GetItemData()
	{
		return ItemData;
	}

private:
	UInventoryItemData* ItemData = nullptr;
};
