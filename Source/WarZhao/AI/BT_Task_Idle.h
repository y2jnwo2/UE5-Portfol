// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/BT_Task_AIBase.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BT_Task_Idle.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UBT_Task_Idle : public UBT_Task_AIBase
{
	GENERATED_BODY()

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds);
};
