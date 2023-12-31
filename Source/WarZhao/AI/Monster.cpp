// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include <GlobalGameInstance/GlobalGameInstance.h>
#include <GlobalGameInstance/Data/MonsterData.h>
#include <UIEX/MiniMapComponent.h>
#include "BehaviorTree/BlackboardComponent.h"

AMonster::AMonster()
{
	MiniMap = CreateDefaultSubobject<UMiniMapComponent>(TEXT("MiniMapComponent"));
	MiniMap->SetupAttachment(RootComponent);
	MiniMap->MiniMapInit(this);

}

void AMonster::BeginPlay()
{
	// 콜백은 Player의 함수가 추가될수가 있는것이다.
	// OnDestroyed.AddDynamic(this, &AProjectTile::DestroyProjectile);

	UGlobalGameInstance* Inst = GetWorld()->GetGameInstance<UGlobalGameInstance>();
	
	if (nullptr != Inst)
	{
		CurMonsterData = Inst->GetMonsterData(DataName);

		SetAllAnimation(CurMonsterData->MapAnimation);
		SetAniState(AIState::DEATH);
	}

	Super::BeginPlay();

	GetBlackboardComponent()->SetValueAsEnum(TEXT("AIState"), static_cast<uint8>(AIState::IDLE));
	GetBlackboardComponent()->SetValueAsString(TEXT("TargetTag"), TEXT("Player"));
	GetBlackboardComponent()->SetValueAsFloat(TEXT("SearchRange"), CurMonsterData->SearchRange);
	GetBlackboardComponent()->SetValueAsFloat(TEXT("AttackRange"), CurMonsterData->AttackRange);
	FVector Pos = GetActorLocation();
	GetBlackboardComponent()->SetValueAsVector(TEXT("OriginPos"), Pos);
}

void AMonster::Destroyed()
{
	Super::Destroyed();

	UGlobalGameInstance* Inst = GetWorld()->GetGameInstance<UGlobalGameInstance>();

	if (nullptr == Inst)
	{
		return;
	}

	TSubclassOf<UObject> Item = Inst->GetSubClass(TEXT("Item"));

	for (size_t i = 0; i < 3; i++)
	{

		FVector RandomPos;

		RandomPos.X = UWarZhaoGlobal::MainRandom.FRandRange(-200, 200);
		RandomPos.Y = UWarZhaoGlobal::MainRandom.FRandRange(-200, 200);
		// 아이템을 드롭하도록 만들어보자.
		{
			// 몬스터 입장에서는 그냥 아이템인지도 알필요가 없고
			// 그냥 내가 죽을때 어떤 액터를 만들뿐이다.
			AActor* Actor = GetWorld()->SpawnActor<AActor>(Item);
			Actor->Tags.Add(TEXT("Item"));
			Actor->SetActorLocation(GetActorLocation()+ RandomPos);
		}
	}
}