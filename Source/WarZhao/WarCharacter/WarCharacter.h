﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnumsAll.h"
#include "WarCharacter.generated.h"

UCLASS()
class WARZHAO_API AWarCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarCharacter();

	UFUNCTION(BlueprintCallable)
	void AnimationTick();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void AttackAction();
	void JumpAction();
	void JumpAxis(float Rate);

	void MoveRight(float Val);
	void MoveForward(float Val);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Pawn")
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		float BaseLookUpRate;

	bool AxisJump = false;

	UPROPERTY(Category = "GameModeValue", EditAnywhere, BlueprintReadWrite)
		WarAniState AniState = WarAniState::Idle;

	UPROPERTY(Category = "AnimationValue", EditAnywhere, BlueprintReadWrite)
		TMap<WarAniState, class UAnimMontage*> AllAnimations;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<UStaticMesh*> WeaponArrays;

	// 디버그 공격거리
	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

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
	void AttackCheck();
};
