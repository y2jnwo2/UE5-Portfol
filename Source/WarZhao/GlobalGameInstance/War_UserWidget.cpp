// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance/War_UserWidget.h"

void UWar_UserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	DebugTextTick = "";
}