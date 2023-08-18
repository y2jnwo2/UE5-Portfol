// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance/ItemBase.h"
#include "GlobalGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
	UGlobalGameInstance* GameInstance = GetWorld()->GetGameInstance<UGlobalGameInstance>();
	Data = GameInstance->GetRandomItemData();


	if (nullptr != Data->Mesh)
	{
		// 내부에 static매쉬 컴포넌트가 있는지 찾고
		UActorComponent* Component = GetComponentByClass(UStaticMeshComponent::StaticClass());
		UStaticMeshComponent* StaticMesh = Cast<UStaticMeshComponent>(Component);
		if (nullptr != StaticMesh)
		{
			StaticMesh->SetStaticMesh(Data->Mesh);
		}
	}
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

