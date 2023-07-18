// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "War_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UWar_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void AddDebugText(const FString& _Text)
	{
		DebugTextTick += _Text + TEXT("\n");
	}

	UPROPERTY(BluePrintReadWrite)
	FString DebugTextTick;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	
};
