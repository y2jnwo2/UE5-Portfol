// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance/ItemBase.h"
#include "GlobalGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include <UIEX/InventoryUserWidget.h>
#include <UIEX/GameHUD.h>

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

void AItemBase::Take(AActor* _Actor)
{
	APlayerController* Con = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AGameHUD* HUD = Con->GetHUD<AGameHUD>();

	if (nullptr == HUD)
	{
		return;
	}
	
	UMainWidget* Widget = HUD->GetMainWidget();
	if (nullptr == Widget)
	{
		return;
	}
	
	UWidget* InvenWidget = Widget->GetWidgetFromName(TEXT("WBP_Inventory"));
	UInventoryUserWidget* Inventory = Cast<UInventoryUserWidget>(InvenWidget);
	if (nullptr == Inventory)
	{
		return;
	}

	Inventory->AddGameItem(Data);
}
