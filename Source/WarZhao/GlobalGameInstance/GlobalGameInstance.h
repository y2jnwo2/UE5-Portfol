// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "GlobalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UGlobalGameInstance : public UGameInstance
{
	GENERATED_BODY()
		
public :
	UGlobalGameInstance();
	~UGlobalGameInstance();

	TSubclassOf<UObject> GetSubClass(FName _Name);

	UStaticMesh* GetMesh(FName _Name);

	struct FMonsterData* GetMonsterData(FName _Name);

	const struct FItemData* GetRandomItemData();

private:
	UPROPERTY()
	UDataTable* MeshDatas;

	UPROPERTY()
		UDataTable* SubClassData;

	UPROPERTY()
		UDataTable* ItemDatas;

	TArray<const struct FItemData*> ItemDataRandoms;

	UPROPERTY()
		UDataTable* MonsterDatas;

	TArray<UStaticMesh*> ArrMesh;

	
};
