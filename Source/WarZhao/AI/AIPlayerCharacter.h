// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalGameInstance/GlobalCharacter.h"
#include "AI/AIEnum.h"
#include "AIPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARZHAO_API AAIPlayerCharacter : public AGlobalCharacter
{
	GENERATED_BODY()
	

public:
	AAIPlayerCharacter();

	void AttackAction();
	void JumpAction();

	void WeaponChange();

	void MoveRight(float Val);
	void MoveForward(float Val);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	void StatusWindowOnOff();

	UFUNCTION(BlueprintCallable)
	void AttUp(class UInventoryItemData* _Data);

protected:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BeginPlay() override;

	// 콤보 공격 
	UFUNCTION()
	void OnAttack();

	UFUNCTION()
	void StartAttack();

	UPROPERTY(Category = "Anim", EditAnyWhere, BlueprintReadWrite)
	class UAnimMontage* AttackMontage;

	bool bIsAttacking;
	TArray<FString> ComboSections = { TEXT("Combo0"), TEXT("Combo1"), TEXT("Combo2"), TEXT("Combo3") };
	int32 ComboIndex;

	// 공격중일때 다시 공격버튼 입력되면 콤보 시전
	bool bCanComboAttack;

private:

	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArmComponent;

	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	void Tick(float _Delta) override;

	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TMap<AIAniState, class UAnimMontage*> MapAnimation;

	UFUNCTION()
		void MontageEnd(UAnimMontage* Anim, bool _Inter);

	UFUNCTION()
		void AnimNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

	float Speed = 800.0f;

	int Att = 10;

};
