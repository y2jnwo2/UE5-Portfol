// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalGameInstance/AICharacter.h"
#include <GlobalGameInstance/GlobalEnums.h>
#include <GlobalGameInstance/Data/MonsterData.h>
#include "Monster.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API AMonster : public AAICharacter
{
	GENERATED_BODY()
	
public:
	AMonster();

	const struct FMonsterData* CurMonsterData;

	void BeginPlay() override;

	// void MonsterDeath();

	void Destroyed() override;

private:
	UPROPERTY(Category = "Monster", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FName DataName = "NONE";

	/*UPROPERTY(Category = "Monster", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UMiniMapComponent* MiniMap;*/
};
