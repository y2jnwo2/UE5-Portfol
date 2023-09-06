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
	// �ݹ��� Player�� �Լ��� �߰��ɼ��� �ִ°��̴�.
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
	GetBlackboardComponent()->SetValueAsFloat(TEXT("SearchRange"), 1500.0f);
	GetBlackboardComponent()->SetValueAsFloat(TEXT("AttackRange"), 200.0f);
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
		// �������� ����ϵ��� ������.
		{
			// ���� ���忡���� �׳� ������������ ���ʿ䰡 ����
			// �׳� ���� ������ � ���͸� ������̴�.
			AActor* Actor = GetWorld()->SpawnActor<AActor>(Item);
			Actor->Tags.Add(TEXT("Item"));
			Actor->SetActorLocation(GetActorLocation()+ RandomPos);
		}
	}
}