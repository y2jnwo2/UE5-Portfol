// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/BT_Task_AIBase.h"
#include "BT_Task_Damaged.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UBT_Task_Damaged : public UBT_Task_AIBase
{
	GENERATED_BODY()

		UBT_Task_Damaged();

protected:

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds);

	
};
