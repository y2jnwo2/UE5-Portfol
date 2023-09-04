// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlaySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UPlaySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "Data", EditAnyWhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	FVector PlayerPos;
	UPROPERTY(Category = "Data", EditAnyWhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	FRotator PlayerRot;
	UPROPERTY(Category = "Data", EditAnyWhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	FVector PlayerScale;
	
	UFUNCTION(Category = "WarZhaoGlobal", BlueprintCallable, meta = (DefaultToSelf = "_Object"))
	void DataSave(ACharacter* _World);
	UFUNCTION(Category = "WarZhaoGlobal", BlueprintCallable, meta = (DefaultToSelf = "_Object"))
	void DataLoad(ACharacter* _World);
};
