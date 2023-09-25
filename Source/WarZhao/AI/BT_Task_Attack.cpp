// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_Attack.h"

UBT_Task_Attack::UBT_Task_Attack()
{
	// 매 프레임마다 실행해라
	bNotifyTick = true;
	// 끝나는 순간 한번 실행해라.
	bNotifyTaskFinished = true;
}

EBTNodeResult::Type UBT_Task_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	GetGlobalCharacter(OwnerComp)->SetAniState(UBT_Task_AIBase::GetAiState(OwnerComp));


	return EBTNodeResult::Type::InProgress;
}

void UBT_Task_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	if (true == IsDeathCheck(OwnerComp))
	{
		SetStateChange(OwnerComp, AIState::DEATH);
		return;
	}

	if (true == IsHPCheck(OwnerComp) && bHit)
	{
		SetStateChange(OwnerComp, AIState::DAMAGED);
		return;
	}

	UAnimMontage* Montage = GetGlobalCharacter(OwnerComp)->GetAnimMontage(UBT_Task_AIBase::GetAiState(OwnerComp));
	float Time = Montage->CalculateSequenceLength();

	if (Time <= GetStateTime(OwnerComp))
	{
		SetStateChange(OwnerComp, AIState::MOVE);
	}
}