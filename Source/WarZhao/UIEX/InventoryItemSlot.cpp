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
		
		return;
	}

	if (nullptr == ItemData->Data)
	{
		ItemBackVisibility = ESlateVisibility::Visible;
		ItemIconVisibility = ESlateVisibility::Hidden;
			ItemCountVisibility = ESlateVisibility::Hidden;
			return;
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
	if (_OtherDragSlot->IsStatus == true && ItemData->Data != nullptr)
	{
		if (_OtherDragSlot->ItemData->Data->Type != ItemData->Data->Type)
		{
			return;
		}
	}

	if (this->ItemData->Data != nullptr)
	{
		if (_OtherDragSlot->ItemData->Data->Type != ItemType::POSTION &&
			ItemData->Data->Type != ItemType::POSTION)
		{
			const FItemData* SwapItemData = _OtherDragSlot->ItemData->Data;
			_OtherDragSlot->ItemData->Data = ItemData->Data;
			ItemData->Data = SwapItemData;
		}

	

		else if (_OtherDragSlot->ItemData->Data->Type != ItemType::POSTION &&
			ItemData->Data->Type != ItemType::NONE)
		{
			const int PotionCount = _OtherDragSlot->ItemData->Count;
			const FItemData* SwapItemData = _OtherDragSlot->ItemData->Data;
			_OtherDragSlot->ItemData->Data = ItemData->Data;
			_OtherDragSlot->ItemData->Count = ItemData->Count;
			ItemData->Data = SwapItemData;
			ItemData->Count = PotionCount;
		}

		else if (_OtherDragSlot->ItemData->Data->Type == ItemType::POSTION ||
			ItemData->Data->Type != ItemType::NONE)
		{
			const int PotionCount = _OtherDragSlot->ItemData->Count;
			const FItemData* SwapItemData = _OtherDragSlot->ItemData->Data;
			_OtherDragSlot->ItemData->Data = ItemData->Data;
			_OtherDragSlot->ItemData->Count = ItemData->Count;
			ItemData->Data = SwapItemData;
			ItemData->Count = PotionCount;
		}
	}
	else
	{
		if (_OtherDragSlot->ItemData->Data->Type != ItemType::POSTION)
		{
			const FItemData* SwapItemData = _OtherDragSlot->ItemData->Data;
			_OtherDragSlot->ItemData->Data = ItemData->Data;
			ItemData->Data = SwapItemData;
		}
		else
		{
			const int PotionCount = _OtherDragSlot->ItemData->Count;
			const FItemData* SwapItemData = _OtherDragSlot->ItemData->Data;
			_OtherDragSlot->ItemData->Data = ItemData->Data;
			_OtherDragSlot->ItemData->Count = ItemData->Count;
			ItemData->Data = SwapItemData;
			ItemData->Count = PotionCount;
		}
	}
	
	if (true == ItemChangeFunction.IsBound())
	{
		ItemChangeFunction.Broadcast();
	}

	SlotDataCheck();
	_OtherDragSlot->SlotDataCheck();
}

UFUNCTION(BlueprintCallable)
void UInventoryItemSlot::DropSetting(UInventoryItemSlot* _OtherDragSlot, bool OutCursor)
{
	if (OutCursor == true)
	{
		if (_OtherDragSlot->ItemData == nullptr)
		{
			return;
		}
		else
		{
			_OtherDragSlot->ItemData->Count -= 1;
		}

	}
	SlotDataCheck();
	_OtherDragSlot->SlotDataCheck();
}

