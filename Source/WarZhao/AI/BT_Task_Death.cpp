// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_Death.h"

UBT_Task_Death::UBT_Task_Death()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
}


EBTNodeResult::Type UBT_Task_Death::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::DEATH);
	return EBTNodeResult::Type::InProgress;
}


void UBT_Task_Death::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	UAnimMontage* Montage = GetGlobalCharacter(OwnerComp)->GetAnimMontage(UBT_Task_AIBase::GetAiState(OwnerComp));
	float Time = Montage->CalculateSequenceLength();
	if (Time <= GetStateTime(OwnerComp))
	{
		GetGlobalCharacter(OwnerComp)->Destroy();
	}
}