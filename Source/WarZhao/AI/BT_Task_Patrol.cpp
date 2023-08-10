// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Task_Patrol.h"
#include <GlobalGameInstance/WarZhaoGlobal.h>
#include "PatrolPositions.h"
#include "GameFramework/CharacterMovementComponent.h"

UBT_Task_Patrol::UBT_Task_Patrol()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
}


EBTNodeResult::Type UBT_Task_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::PATROL);

	UCharacterMovementComponent* MoveCom = Cast<UCharacterMovementComponent>(GetGlobalCharacter(OwnerComp)->GetMovementComponent());

	if (nullptr != MoveCom)
	{
		MoveCom->MaxWalkSpeed = 200.0f;
	}


	int PatrolCount = UWarZhaoGlobal::MainRandom.RandRange(4, 8);

	UPatrolPositions* PP = NewObject<UPatrolPositions>();
	GetBlackboardComponent(OwnerComp)->SetValueAsObject(TEXT("PatrolPositions"), PP);


	PP->CurrentIndex = 0;
	// TArray<FVector> Positions;

	FVector OriginPos = GetBlackboardComponent(OwnerComp)->GetValueAsVector(TEXT("OriginPos"));

	// FVector OriginPos = GetGlobalCharacter(OwnerComp)->GetActorLocation();

	float SearchRange = GetBlackboardComponent(OwnerComp)->GetValueAsFloat(TEXT("SearchRange"));

	for (size_t i = 0; i < PatrolCount; i++)
	{
		FVector RandomDir;
		RandomDir.X = UWarZhaoGlobal::MainRandom.FRandRange(-100.0f, 100.0f);
		RandomDir.Y = UWarZhaoGlobal::MainRandom.FRandRange(-100.0f, 100.0f);
		RandomDir.Normalize();
		RandomDir *= UWarZhaoGlobal::MainRandom.FRandRange(SearchRange * 0.4f, SearchRange);
		RandomDir += OriginPos;
		PP->Positions.Add(RandomDir);
	}

	PP->Positions.Add(OriginPos);

	// ���ʿ� �������� ������ ���� �־���.
	// ���⿡ �־����Ƿ� ������ ������Ʈ�� �� �޸𸮸� �����ٰ��̴ٸ� �����ϰ� �ִ�.

	return EBTNodeResult::Type::InProgress;
}

void UBT_Task_Patrol::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	if (true == IsDeathCheck(OwnerComp))
	{
		SetStateChange(OwnerComp, AIState::DEATH);
		return;
	}

	UObject* PPObject = GetBlackboardComponent(OwnerComp)->GetValueAsObject(TEXT("PatrolPositions"));

	if (nullptr == PPObject)
	{
		SetStateChange(OwnerComp, AIState::IDLE);
		return;
	}

	UPatrolPositions* PP = Cast<UPatrolPositions>(PPObject);

	TArray<FVector>& Positions = PP->Positions;
	int CurrentIndex = PP->CurrentIndex;

	if (CurrentIndex == Positions.Num())
	{
		SetStateChange(OwnerComp, AIState::IDLE);
		return;
	}

	FVector TargetPos = Positions[CurrentIndex];
	FVector ThisPos = GetGlobalCharacter(OwnerComp)->GetActorLocation();


	AActor* ResultActor = GetTargetSearch(OwnerComp);

	if (nullptr != ResultActor)
	{
		GetBlackboardComponent(OwnerComp)->SetValueAsObject(TEXT("TargetActor"), ResultActor);
		SetStateChange(OwnerComp, AIState::MOVE);
		return;
	}


	{
		TargetPos.Z = 0.0f;
		ThisPos.Z = 0.0f;

		FVector Dir = TargetPos - ThisPos;
		Dir.Normalize();

		FVector OtherForward = GetGlobalCharacter(OwnerComp)->GetActorForwardVector();
		OtherForward.Normalize();

		FVector Cross = FVector::CrossProduct(OtherForward, Dir);

		float Angle0 = Dir.Rotation().Yaw;
		float Angle1 = OtherForward.Rotation().Yaw;

		if (FMath::Abs(Angle0 - Angle1) >= 10.0f)
		{
			FRotator Rot = FRotator::MakeFromEuler({ 0, 0, Cross.Z * 500.0f * DelataSeconds });
			GetGlobalCharacter(OwnerComp)->AddActorWorldRotation(Rot);
		}
		else {
			FRotator Rot = Dir.Rotation();
			GetGlobalCharacter(OwnerComp)->SetActorRotation(Rot);
		}
	}



	{
		FVector Dir = TargetPos - ThisPos;

		GetGlobalCharacter(OwnerComp)->AddMovementInput(Dir);

		if (50.0f >= Dir.Size())
		{
			++PP->CurrentIndex;
			return;
		}
	}


}