// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	bool CheckAllWidgetHidden();

	UFUNCTION(BlueprintCallable)
	void SetOptionOnOffSwitch()
	{
		OptionOnOff = OptionOnOff == ESlateVisibility::Hidden? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}
	void SetStatusWindowOnOffSwitch()
	{
		StatusWindowOnOff = StatusWindowOnOff == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}

	void SetInventoryOnOffSwitch()
	{
		InventoryOnOff = InventoryOnOff == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}

protected:
	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ESlateVisibility InventoryOnOff = ESlateVisibility::Hidden;

	UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ESlateVisibility StatusWindowOnOff = ESlateVisibility::Hidden;

	UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ESlateVisibility OptionOnOff = ESlateVisibility::Hidden;
		
		class UInventoryUserWidget* Inven;

		UPROPERTY()
		TArray<UUserWidget*> AllWidget;
		UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
		bool AllHidden = true;
};
