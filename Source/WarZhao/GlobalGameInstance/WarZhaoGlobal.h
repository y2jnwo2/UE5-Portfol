// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarZhaoGlobal.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UWarZhaoGlobal : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static FRandomStream MainRandom;

	UFUNCTION(BlueprintCallable, category = "WarZhaoGlobal")
	static void WarDebugTextInit();

	UFUNCTION(BlueprintCallable, category = "WarZhaoGlobal",meta = (DefaultToSelf = "_Object"))
	static void WarDebugTextPrint(class AActor* _Object, const FString& _Text);

	static class UWar_UserWidget* DebugWidget;
};
