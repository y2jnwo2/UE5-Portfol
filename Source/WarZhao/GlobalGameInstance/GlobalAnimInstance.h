// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GlobalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API UGlobalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public :
	UPROPERTY(Category = "GameModeValue", EditAnywhere, BlueprintReadWrite)

		int AniState = 0;
		int DefaultAniState = -1;

	TMap<int, class UAnimMontage*> AllAnimations;

	class UAnimMontage* CurMontage = nullptr;

	UFUNCTION()
		void MontageEnd(UAnimMontage* ANim, bool _Inte);

	template<typename EnumType>
	void SetDefaultAniState(EnumType _DefaultState)
	{
		DefaultAniState = static_cast<int>(_DefaultState);
	}

	void SetDefaultAniState(int _DefaultState)
	{
		DefaultAniState = _DefaultState;
	}

	// 콤보 어택 구현
	UFUNCTION()
	void AnimNotify_AttackEnd();

	UFUNCTION()
	void AnimNotify_CheckComboAttack();

	UFUNCTION()
	void AnimNotify_InitComboAttack();

protected:
	void NativeBeginPlay() override;
	void NativeUpdateAnimation(float _DeltaTime) override;
};
