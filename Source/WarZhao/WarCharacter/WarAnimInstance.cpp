// Fill out your copyright notice in the Description page of Project Settings.


#include "WarAnimInstance.h"
#include "WarCharacter.h"
#include "Animation/AnimMontage.h"
#include "Kismet/GameplayStatics.h"

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

void UWarAnimInstance::AnimNotify_AttackEnd()
{
	AWarCharacter* PlayerAvatar = Cast<AWarCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerAvatar)
	{
		PlayerAvatar->bIsAttacking = false;
	}
}

void UWarAnimInstance::AnimNotify_CheckComboAttack()
{
	AWarCharacter* PlayerAvatar = Cast<AWarCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerAvatar->ComboIndex >= PlayerAvatar->ComboSections.Num() - 1)
	{
		PlayerAvatar->ComboIndex = 0;
	}

	if (PlayerAvatar->bCanComboAttack == true)
	{
		PlayerAvatar->ComboIndex++;
		PlayerAvatar->bCanComboAttack = false;
		PlayerAvatar->StartAttack();
	}
	else if (PlayerAvatar->bCanComboAttack == false)
	{
		PlayerAvatar->ComboIndex = 0;
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::MakeRandomColor(),
			FString::Printf(TEXT("ComboIndex : &d"), PlayerAvatar->ComboIndex));
	}
}

void UWarAnimInstance::AnimNotify_InitComboAttack()
{
	AWarCharacter* PlayerAvatar = Cast<AWarCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerAvatar)
	{
		PlayerAvatar->ComboIndex = 0;
		PlayerAvatar->bCanComboAttack = false;
	}
}




