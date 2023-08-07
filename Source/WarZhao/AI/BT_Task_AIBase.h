// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include <GlobalGameInstance/GlobalCharacter.h>
#include <AI/AICon.h>
#include <GlobalGameInstance/GlobalEnums.h>
#include <BehaviorTree/BlackboardComponent.h>
#include "BT_Task_AIBase.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UBT_Task_AIBase : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBT_Task_AIBase();
	void OnGameplayTaskActivated(class UGameplayTask&) override;

	float GetStateTime(UBehaviorTreeComponent& OwnerComp);
	AIState GetAiState(UBehaviorTreeComponent& OwnerComp);
	void ResetStateTime(UBehaviorTreeComponent& OwnerComp);

	template<typename EnumType>
	void SetStateChange(UBehaviorTreeComponent& OwnerComp, EnumType _State)
	{
		SetStateChange(OwnerComp, static_cast<uint8>(_State));
	}

	void SetStateChange(UBehaviorTreeComponent& OwnerComp, uint8 _State);

	class AGlobalCharacter* GetGlobalCharacter(UBehaviorTreeComponent& OwnerComp);
	
	class AActor* GetTargetSearch(UBehaviorTreeComponent& OwnerComp);

	class UBlackboardComponent* GetBlackboardComponent(UBehaviorTreeComponent& OwnerComp);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	bool IsDeathCheck(UBehaviorTreeComponent& OwnerComp);
};
