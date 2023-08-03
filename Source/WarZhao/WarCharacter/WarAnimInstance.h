// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnumsAll.h"
#include "GameFramework/Character.h"
#include "WarAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UWarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public :
	UPROPERTY(Category = "GameModeValue", EditAnyWhere, BlueprintReadWrite)
		WarAniState AniState = WarAniState::Idle;

	TMap<WarAniState, class UAnimMontage*> AllAnimations;

	UFUNCTION()
		void MontageEnd(UAnimMontage* Anim, bool _Inter);

	// ÄÞº¸ °ø°Ý 
	UFUNCTION()
		void OnAttack();

	UFUNCTION()
		void StartAttack();

	UPROPERTY(Category = "Anim", EditAnyWhere, BlueprintReadWrite)
		class UAnimMontage* AttackMontage;

	bool bIsAttacking;
	TArray<FString> ComboSections = { TEXT("Combo0"), TEXT("Combo1"), TEXT("Combo2"), TEXT("Combo3") };
	int32 ComboIndex;

protected:
	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float _DeltaTime) override;
};
