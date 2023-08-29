// Fill out your copyright notice in the Description page of Project Settings.


#include "UIEX/InventoryUserWidget.h"
#include <GlobalGameInstance/GlobalGameInstance.h>
#include "InventoryItemSlot.h"
#include "InventoryItemData.h"

UInventoryUserWidget* UInventoryUserWidget::InvenWidget = nullptr;

void UInventoryUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	InvenWidget = this;

	InvenList = Cast<UTileView>(GetWidgetFromName(TEXT("InvenTileView")));

	for (size_t i = 0; i < 20; i++)
	{
		UInventoryItemData* ItemObject = NewObject<UInventoryItemData>();
		ItemObject->Data = nullptr;
		InvenList->AddItem(ItemObject);
	}

	UGlobalGameInstance* GameInstance = GetWorld()->GetGameInstance<UGlobalGameInstance>();

	const TArray<UObject*>& Items = InvenList->GetListItems();
	for (size_t i = 0; i < 3; i++)
	{
		UInventoryItemData* DataObject = Cast<UInventoryItemData>(Items[i]);
		DataObject->Data = GameInstance->GetRandomItemData();
	}
}

void UInventoryUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	const TArray<UObject*>& Items = InvenList->GetListItems();
	for (size_t i = 0; i < Items.Num(); i++)
	{
		UInventoryItemData* DataObject = Cast<UInventoryItemData>(Items[i]);

		if (nullptr == DataObject->Widget)
		{
			continue;
		}

		UInventoryItemSlot* SlotWidget = DataObject->Widget;
		SlotWidget->SlotDataCheck();
	}
}
void UInventoryUserWidget::AddInvenItem(UObject* _Data, UUserWidget* _Widget)
{
	UInventoryItemSlot* ItemSlotWidget = Cast<UInventoryItemSlot>(_Widget);
	UInventoryItemData* InvenSlotData = Cast<UInventoryItemData>(_Data);

	if (nullptr == ItemSlotWidget)
	{
		return;
	}
	InvenSlotData->Widget = ItemSlotWidget;
	ItemSlotWidget->SetItemData(InvenSlotData);
}

void UInventoryUserWidget::AddGameItem(const FItemData* Data)
{
	const TArray<UObject*>& Items = InvenList->GetListItems();

	for (size_t i = 0; i < Items.Num(); i++)
	{
		UInventoryItemData* DataObject = Cast<UInventoryItemData>(Items[i]);
		if (nullptr == DataObject->Data)
		{
			DataObject->Data = Data;

			return;
		}
	}
	return;
}

void UInventoryUserWidget::NewWidget(UUserWidget* _Widget)
{
	int a = 0;
}

