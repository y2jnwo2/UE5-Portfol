// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnumsAll.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
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

	// 콤보 어택 구현
	UFUNCTION()
	void AnimNotify_AttackEnd();


protected:
	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float _DeltaTime) override;
};
