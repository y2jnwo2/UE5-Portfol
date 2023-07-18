// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance.h"
//#include "Data/GameMeshData.h"

UGlobalGameInstance::UGlobalGameInsatance()
{
	/*{
		FString DataPath = TEXT("/Script/Engine.DataTable'/Game/BluePrint/Global/Data/DT_GameMeshData.DT_GameMeshData'");
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
	}*/
}
UGlobalGameInstance::~UGlobalGameInstance()
{

}

//UStaticMesh* UGlobalGameInstance::GetMesh(FName _Name)
//{
//	if (nullptr == MeshDatas)
//	{
//		return nullptr;
//	}
//
//	FGameMeshData* FindTable = MeshDatas->FindRow<FGameMeshData>(_Name, _Name.ToString());
//
//	if (nullptr == FindTable)
//	{
//		return nullptr;
//	}
//
//	return FindTable->Mesh;
//}

