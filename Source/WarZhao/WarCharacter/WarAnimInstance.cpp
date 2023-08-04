// Fill out your copyright notice in the Description page of Project Settings.


#include "WarAnimInstance.h"
#include "WarCharacter.h"
#include "Animation/AnimMontage.h"

void UWarAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OnMontageBlendingOut.AddDynamic(this, &UWarAnimInstance::MontageEnd);

	AWarCharacter* Character = Cast<AWarCharacter>(GetOwningActor());

	if (nullptr == Character && false == Character->IsValidLowLevel())
	{
		return;
	}

	AllAnimations = Character->AllAnimations;

	// 처음엔 공격중이 아니니 false로 시작
	bIsAttacking = false;

	ComboIndex = 0;
}

void UWarAnimInstance::NativeUpdateAnimation(float _DeltaTime)
{
	Super::NativeUpdateAnimation(_DeltaTime);

	if (0 == AllAnimations.Num())
	{
		return;
	}

	AWarCharacter* Character = Cast<AWarCharacter>(GetOwningActor());

	if (nullptr == Character && false == Character->IsValidLowLevel())
	{
		return;
	}

	AniState = Character->AniState;

	class UAnimMontage* Montage = AllAnimations[AniState];

	if (nullptr == Montage)
	{
		return;
	}

	if (false == Montage_IsPlaying(Montage))
	{
		Montage_Play(Montage, 1.0f);
	}

}

void UWarAnimInstance::MontageEnd(UAnimMontage* Anim, bool _Inter)
{
	TSubclassOf<UAnimInstance> Inst = UWarAnimInstance::StaticClass();

	AWarCharacter* Character = Cast<AWarCharacter>(GetOwningActor());
	
	if (nullptr == Character && false == Character->IsValidLowLevel())
	{
		return;
	}

	if (AllAnimations[WarAniState::Attack] == Anim)
	{
		AniState = WarAniState::Idle;
		Character->AniState = AniState;
		Montage_Play(AllAnimations[WarAniState::Idle], 1.0f);
	}

	if (AllAnimations[WarAniState::Jump] == Anim)
	{
		AniState = WarAniState::Idle;
		Character->AniState = AniState;
		Montage_Play(AllAnimations[WarAniState::Idle], 1.0f);
	}

	
}

// 콤보공격 구현
void UWarAnimInstance::OnAttack()
{
	if (bIsAttacking == false)
	{
		StartAttack();
		bIsAttacking = true;
	}
}

void UWarAnimInstance::StartAttack()
{
	/*AWarCharacter* WarActor = Cast<AWarCharacter>();

	if (null == WarActor)
	{
		return;
	}
	UWarAnimInstance* AnimInstance = WarActor->GetMesh()->GetAnimInstance();*/

	/*UWarAnimInstance* AnimInstance = Cast<UWarAnimInstance>(GetMesh()->GetAnimInstance());
	
	if (!AnimInstance || !AttackMontage)
	{
		return;
	}

	if (AnimInstance->Montage_IsPlaying(AttackMontage) == false)
	{
		AnimInstance->Montage_Play(AttackMontage);
	}*/
	
}
