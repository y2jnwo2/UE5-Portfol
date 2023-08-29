// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "InventoryUserWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AllWidget.Add(Cast<UUserWidget>(GetWidgetFromName(TEXT("WBP_Inventory"))));
	AllWidget.Add(Cast<UUserWidget>(GetWidgetFromName(TEXT("WBP_Status"))));
}

void UMainWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

}

bool UMainWidget::CheckAllWidgetHidden()
{
	bool AllHiddenCheck = true;

	for (size_t i = 0; i < AllWidget.Num(); i++)
	{
		if (AllWidget[i]->GetVisibility() == ESlateVisibility::Visible)
		{
			AllHiddenCheck = false;
		}
	}

	if (AllHiddenCheck != AllHidden)
	{
		AllHidden = AllHiddenCheck;
		return true;
	}
	return false;
}
