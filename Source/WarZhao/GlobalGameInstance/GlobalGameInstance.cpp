// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance.h"
#include "Data/GameMeshData.h"
#include <GlobalGameInstance/Data/SubClassData.h>
#include <GlobalGameInstance/Data/MonsterData.h>
#include <GlobalGameInstance/Data/ItemData.h>
#include <GlobalGameInstance/WarZhaoGlobal.h>

UGlobalGameInstance::UGlobalGameInstance()
{
	{
		FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BluePrints/Global/Data/DT_GameMeshData.DT_GameMeshData'");
		ConstructorHelpers::FObjectFinder<UDataTable> DataTable(*DataPath);

		if (DataTable.Succeeded())
		{
			MeshDatas = DataTable.Object;

			TArray<FName> ArrayName = MeshDatas->GetRowNames();

			for (size_t i = 0; i < ArrayName.Num(); i++)
			{
				FGameMeshData* FindTable = MeshDatas->FindRow<FGameMeshData>(ArrayName[i], ArrayName[i].ToString());

				int a = 0;
			}


		}
	}

	{
		FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BluePrints/Global/Data/DT_GameItemData.DT_GameItemData'");
		ConstructorHelpers::FObjectFinder<UDataTable> DataTable(*DataPath);

		if (DataTable.Succeeded())
		{
			ItemDatas = DataTable.Object;

			TArray<FName> ArrayName = ItemDatas->GetRowNames();

			for (size_t i = 0; i < ArrayName.Num(); i++)
			{
				FItemData* ItemData = ItemDatas->FindRow<FItemData>(ArrayName[i], ArrayName[i].ToString());
				ItemDataRandoms.Add(ItemData);
			}
		}
	}
		{
			FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BluePrints/Global/Data/DT_GameSubClassData.DT_GameSubClassData'");
			ConstructorHelpers::FObjectFinder<UDataTable> DataTable(*DataPath);  
			   
			if (DataTable.Succeeded())
			{
				SubClassData = DataTable.Object;
			}
		}

		{

			FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BluePrints/AI/DT_MonsterData.DT_MonsterData'");
			ConstructorHelpers::FObjectFinder<UDataTable> DataTable(*DataPath);

			if (DataTable.Succeeded())
			{
				MonsterDatas = DataTable.Object;
			}

		
	}

	UWarZhaoGlobal::MainRandom.GenerateNewSeed();
}
UGlobalGameInstance::~UGlobalGameInstance()
{

}

const struct FItemData* UGlobalGameInstance::GetRandomItemData()
{
	if (true == ItemDataRandoms.IsEmpty())
	{
		return nullptr;
	}

	return ItemDataRandoms[UWarZhaoGlobal::MainRandom.RandRange(0, ItemDataRandoms.Num() - 1)];
}

TSubclassOf<UObject> UGlobalGameInstance::GetSubClass(FName _Name)
{
	if (nullptr == SubClassData)
	{
		return nullptr;
	}

	FSubClassData* FindTable = SubClassData->FindRow<FSubClassData>(_Name, _Name.ToString());

	if (nullptr == FindTable)
	{
		return nullptr;
	}

	return FindTable->Object;
}

UStaticMesh* UGlobalGameInstance::GetMesh(FName _Name)
{
	if (nullptr == MeshDatas)
	{
		return nullptr;
	}

	FGameMeshData* FindTable = MeshDatas->FindRow<FGameMeshData>(_Name, _Name.ToString());

	if (nullptr == FindTable)
	{
		return nullptr;
	}

	return FindTable->Mesh;
}

FMonsterData* UGlobalGameInstance::GetMonsterData(FName _Name)
{
	if (nullptr == MonsterDatas)
	{
		return nullptr;
	}

	FMonsterData* FindTable = MonsterDatas->FindRow<FMonsterData>(_Name, _Name.ToString());

	if (nullptr == FindTable)
	{
		return nullptr;
	}

	return FindTable;
}
