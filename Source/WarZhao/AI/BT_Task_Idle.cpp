// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_Idle.h"
#include <GlobalGameInstance/GlobalCharacter.h>
#include <AI/AICon.h>
#include <GlobalGameInstance/GlobalEnums.h>
#include <BehaviorTree/BlackboardComponent.h>
#include "Kismet/GameplayStatics.h"
#include "Math/NumericLimits.h"

EBTNodeResult::Type UBT_Task_Idle::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::IDLE);

	GetBlackboardComponent(OwnerComp)->SetValueAsObject(TEXT("TargetActor"), nullptr);

	return EBTNodeResult::Type::InProgress;
}

void UBT_Task_Idle::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	bHit = false;

	if (true == IsDeathCheck(OwnerComp))
	{
		SetStateChange(OwnerComp, AIState::DEATH);
		return;
	}

	/*if (true == IsHPCheck(OwnerComp))
	{
		SetStateChange(OwnerComp, AIState::DAMAGED);
		return;
	}*/

	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	if (2.0f <= GetStateTime(OwnerComp))
	{
		// ���������� ������ �̿��ϴ°�.
		FRandomStream Stream;
		// �˾Ƽ� �ð��� ���� ���ϴ� ���� �õ尪���� ��´�.
		Stream.GenerateNewSeed();

		int Value = Stream.RandRange(0, 1);

		// UE_LOG(LogTemp, Error, TEXT("%S(%u)> %d"), __FUNCTION__, __LINE__, Value);

		ResetStateTime(OwnerComp);

		//if (Value == 0)
		//{
		SetStateChange(OwnerComp, AIState::PATROL);
		return;
		//}


		// �׷� �����ұ�?
		// �׳� 5�ʰ� �ٽ� �������.
		// SetStateChange(OwnerComp, AIState::MOVE);
		// return;
	}

	AActor* ResultActor = GetTargetSearch(OwnerComp);

	if (nullptr != ResultActor)
	{
		GetBlackboardComponent(OwnerComp)->SetValueAsObject(TEXT("TargetActor"), ResultActor);
		SetStateChange(OwnerComp, AIState::MOVE);
		return;
	}

	//�ٽ��� �÷��̾ ã�Ƴ��°�.
	// GetGlobalCharacter(OwnerComp)->GetLevel()->;


	return;
}