// Fill out your copyright notice in the Description page of Project Settings.


#include "UIEX/InventoryItemSlot.h"

void UInventoryItemSlot::NativeConstruct()
{
	Super::NativeConstruct();

	ItemIconBack = Cast<UImage>(GetWidgetFromName(TEXT("ItemBack:")));

	ItemIconImage = Cast<UImage>(GetWidgetFromName(TEXT("ItemIcon")));
	ItemCountBlock = Cast<UTextBlock>
		(GetWidgetFromName(TEXT("ItemCount")));

	ItemData = NewObject<UInventoryItemData>();
}

void UInventoryItemSlot::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UInventoryItemSlot::SetItemData(UInventoryItemData* _ItemData)
{
	ItemData = _ItemData;
	SlotDataCheck();
}

void UInventoryItemSlot::SlotDataCheck()
{
	if (nullptr == ItemData)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == ItemData)"), __FUNCTION__, __LINE__);
		// 치명적인 에러
		//ItemBackVisibility = ESlateVisibility::Visible;
		//ItemIconVisibility = ESlateVisibility::Hidden;
		//ItemCountVisibility = ESlateVisibility::Hidden;
		return;
	}

	if (nullptr == ItemData->Data)
	{
		ItemBackVisibility = ESlateVisibility::Visible;
		ItemIconVisibility = ESlateVisibility::Hidden;
			ItemCountVisibility = ESlateVisibility::Hidden;
	}

	if (nullptr != ItemData->Data)
	{
		ItemIconVisibility = ESlateVisibility::Visible;
		ItemIconImage->SetBrushFromTexture(Cast<UTexture2D>(ItemData->Data->Icon));
		ItemCountValue = ItemData->Count;

		if (1 < ItemData->Data->StackMax)
		{
			ItemCountVisibility = ESlateVisibility::Visible;
		}
		else
		{
			ItemCountVisibility = ESlateVisibility::Hidden;
		}
	}
}

void UInventoryItemSlot::DragSetting(UInventoryItemSlot* _OtherDragSlot)
{
	ItemIconBack = Cast<UImage>(GetWidgetFromName(TEXT("ItemBack")));
		ItemIconImage = Cast<UImage>(GetWidgetFromName(TEXT("ItemIcon")));
		ItemCountBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("ItemCount")));

		ItemBackVisibility = ESlateVisibility::Hidden;

		SetItemData(_OtherDragSlot->ItemData);
}

void UInventoryItemSlot::MoveSetting(UInventoryItemSlot* _OtherDragSlot)
{
	if (_OtherDragSlot == this)
	{
		return;
	}

	if (ItemTypeValue != ItemType::NONE && _OtherDragSlot->ItemData->Data->Type != ItemTypeValue)
	{
		return;
	}

	UInventoryItemData* SwapItemData = _OtherDragSlot->ItemData;
	_OtherDragSlot->ItemData = ItemData;
	ItemData = SwapItemData;

	if (true == ItemChangeFunction.IsBound())
	{
		ItemChangeFunction.Broadcast();
	}

	SlotDataCheck();
	_OtherDragSlot->SlotDataCheck();
}
