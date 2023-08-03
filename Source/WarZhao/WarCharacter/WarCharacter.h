// Fill out your copyright notice in the Description page of Project Settings.

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
		USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		TArray<USkeletalMesh*> WeaponArrays;

	// 디버그 공격거리
	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	
private:
	void AttackCheck();
};
