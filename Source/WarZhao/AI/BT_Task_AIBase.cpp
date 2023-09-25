// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_AIBase.h"
#include "Kismet/GameplayStatics.h"
#include <GlobalGameInstance/GlobalEnums.h>

UBT_Task_AIBase::UBT_Task_AIBase()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;

}

void UBT_Task_AIBase::OnGameplayTaskActivated(class UGameplayTask&)
{

}

float UBT_Task_AIBase::GetStateTime(UBehaviorTreeComponent& OwnerComp)
{
	UBlackboardComponent* BlockBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlockBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return 0.0f;
	}

	float StateTime = BlockBoard->GetValueAsFloat(TEXT("StateTime"));

	return StateTime;
}

AIState UBT_Task_AIBase::GetAiState(UBehaviorTreeComponent& OwnerComp)
{
	UBlackboardComponent* BlockBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlockBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return AIState::NONE;
	}

	uint8 Enum = BlockBoard->GetValueAsEnum(TEXT("AIState"));

	return static_cast<AIState>(Enum);

}

void UBT_Task_AIBase::ResetStateTime(UBehaviorTreeComponent& OwnerComp)
{
	UBlackboardComponent* BlockBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlockBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return;
	}

	BlockBoard->SetValueAsFloat(TEXT("StateTime"), 0.0f);
}

AGlobalCharacter* UBT_Task_AIBase::GetGlobalCharacter(UBehaviorTreeComponent& OwnerComp)
{
	AAICon* AiCon = OwnerComp.GetOwner<AAICon>();
	if (nullptr == AiCon || false == AiCon->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == Chracter || false == Chracter->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		// 정상적이지 않은 뭔가가 
		return nullptr;
	}

	// 컨트롤러에게 내가 조작하는 Pawn은 GetPawn을 사용한다.
	AGlobalCharacter* Character = AiCon->GetPawn<AGlobalCharacter>();

	if (nullptr == Character || false == Character->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == Chracter || false == Chracter->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		// 정상적이지 않은 뭔가가 
		return nullptr;
	}

	return Character;
}

UBlackboardComponent* UBT_Task_AIBase::GetBlackboardComponent(UBehaviorTreeComponent& OwnerComp)
{
	UBlackboardComponent* BlockBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlockBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return BlockBoard;
}



EBTNodeResult::Type UBT_Task_AIBase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Type::InProgress;
}

void UBT_Task_AIBase::SetStateChange(UBehaviorTreeComponent& OwnerComp, uint8 _State)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlackBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return;
	}

	BlackBoard->SetValueAsEnum(TEXT("AIState"), _State);

	ResetStateTime(OwnerComp);

	FinishLatentTask(OwnerComp, EBTNodeResult::Type::Failed);
}


void UBT_Task_AIBase::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();

	if (nullptr == BlackBoard)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BlockBoard)"), __FUNCTION__, __LINE__);
		return;
	}

	float StateTime = BlackBoard->GetValueAsFloat(TEXT("StateTime"));
	StateTime += DelataSeconds;
	BlackBoard->SetValueAsFloat(TEXT("StateTime"), StateTime);


}




class AActor* UBT_Task_AIBase::GetTargetSearch(UBehaviorTreeComponent& OwnerComp)
{
	FString TargetTag = GetBlackboardComponent(OwnerComp)->GetValueAsString(TEXT("TargetTag"));
	TArray<AActor*> TargetActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), *TargetTag, TargetActors);

	AGlobalCharacter* Pawn = GetGlobalCharacter(OwnerComp);

	float SearchRange = GetBlackboardComponent(OwnerComp)->GetValueAsFloat(TEXT("SearchRange"));


	AActor* ResultActor = nullptr;

	if (0 != TargetActors.Num())
	{
		float Range = TNumericLimits<float>::Max();

		for (size_t i = 0; i < TargetActors.Num(); i++)
		{
			float Dis = (Pawn->GetActorLocation() - TargetActors[i]->GetActorLocation()).Size();

			if (SearchRange <= Dis)
			{
				continue;
			}

			if (Range > Dis)
			{
				Range = Dis;
				ResultActor = TargetActors[i];
			}
		}
	}

	return ResultActor;
}

bool UBT_Task_AIBase::IsDeathCheck(UBehaviorTreeComponent& OwnerComp)
{
	if (0 >= GetGlobalCharacter(OwnerComp)->GetHP())
	{
		SetStateChange(OwnerComp, AIState::DEATH);
		return true;
	}

	return false;
}

bool UBT_Task_AIBase::IsHPCheck(UBehaviorTreeComponent& OwnerComp)
{
	if (GetGlobalCharacter(OwnerComp)->GetHP() < HPRef)
	{
		HPRef -= 3.f;
		SetStateChange(OwnerComp, AIState::DAMAGED);
		return true;
	}
	return false;
}
