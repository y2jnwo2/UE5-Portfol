// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <UIEX/MainWidget.h>
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AGameHUD();
	~AGameHUD();

	UMainWidget* GetMainWidget()
	{
		return MainWidget;
	}

protected:
	void BeginPlay() override;
	void Tick(float _Delta) override;

private:
	UMainWidget* MainWidget = nullptr;
};
