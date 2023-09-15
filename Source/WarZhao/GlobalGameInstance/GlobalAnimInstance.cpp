// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalAnimInstance.h"
#include "GlobalCharacter.h"
#include <GlobalGameInstance/Data/MonsterData.h>
#include "WarZhaoGlobal.h"
#include <AI/AIPlayerCharacter.h>
#include <Kismet/GameplayStatics.h>

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
	AAIPlayerCharacter* Player = Cast<AAIPlayerCharacter>(GetOwningActor());

	if (nullptr == Character && false == Character->IsValidLowLevel())
	{
		return;
	}

	if (!Character->ActorHasTag("Monster") && nullptr == Player && false == Player->IsValidLowLevel())
	{
		return;
	}
	
	AniState = Character->GetAniState();

	class UAnimMontage* Montage = AllAnimations[AniState];

	if (nullptr == Montage)
	{
		return;
	}

	if (false == Montage_IsPlaying(Montage))
	{
		
		if (Character->ActorHasTag("Monster") || Player->bIsAttacking == false )
		{
			CurMontage = Montage;
			Montage_Play(Montage, 1.0f);
		}
	}
	
}
void UGlobalAnimInstance::MontageEnd(UAnimMontage * Anim, bool _Inter)
{

}

void UGlobalAnimInstance::AnimNotify_AttackEnd()
{
	AAIPlayerCharacter* PlayerAvatar = Cast<AAIPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerAvatar)
	{
		PlayerAvatar->bIsAttacking = false;
	}
}

void UGlobalAnimInstance::AnimNotify_CheckComboAttack()
{
	AAIPlayerCharacter* PlayerAvatar = Cast<AAIPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

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

	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::MakeRandomColor(),
			FString::Printf(TEXT("ComboIndex : %d"), PlayerAvatar->ComboIndex));
	}*/
}

void UGlobalAnimInstance::AnimNotify_InitComboAttack()
{
	AAIPlayerCharacter* PlayerAvatar = Cast<AAIPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerAvatar)
	{
		PlayerAvatar->ComboIndex = 0;
		PlayerAvatar->bCanComboAttack = false;
	}
}
