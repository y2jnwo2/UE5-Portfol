// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalAnimInstance.h"
#include "GlobalCharacter.h"
#include <GlobalGameInstance/Data/MonsterData.h>
#include "WarZhaoGlobal.h"

void UGlobalAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OnMontageBlendingOut.AddDynamic(this, &UGlobalAnimInstance::MontageEnd);
}

void UGlobalAnimInstance::NativeUpdateAnimation(float _DeltaTime)
{
	Super::NativeUpdateAnimation(_DeltaTime);

	if (0 == AllAnimations.Num())
	{
		return;
	}

	AGlobalCharacter* Character = Cast<AGlobalCharacter>(GetOwningActor());

	if (nullptr == Character && false == Character->IsValidLowLevel())
	{
		return;
	}

	class UAnimMontage* Montage = AllAnimations[AniState];

	if (nullptr == Montage)
	{
		return;
	}

	if (false == Montage_IsPlaying(Montage))
	{
		CurMontage = Montage;
		Montage_Play(Montage, 1.0f);
	}
}
	void UGlobalAnimInstance::MontageEnd(UAnimMontage * Anim, bool _Inter)
	{

	}
