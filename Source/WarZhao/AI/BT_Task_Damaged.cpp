// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BT_Task_Damaged.h"

UBT_Task_Damaged::UBT_Task_Damaged()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;

}


EBTNodeResult::Type UBT_Task_Damaged::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::DAMAGED);
	return EBTNodeResult::Type::InProgress;

	bHit = true;
}


void UBT_Task_Damaged::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	UAnimMontage* Montage = GetGlobalCharacter(OwnerComp)->GetAnimMontage(UBT_Task_AIBase::GetAiState(OwnerComp));
	OwnerComp.Deactivate();

	float Time = Montage->CalculateSequenceLength();
	if (Time <= GetStateTime(OwnerComp))
	{
			SetStateChange(OwnerComp, AIState::IDLE);
			return;
		
	}

	
}

