//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GlobalGameInstance/GlobalCharacter.h"
//#include "AI/AIEnum.h"
//#include "AICharacter.generated.h"
//
///**
// * 
// */
//UCLASS()
//class WARZHAO_API AAICharacter : public AGlobalCharacter
//{
//	GENERATED_BODY()
//	
//
//public:
//	AAICharacter();
//
//	void AttackAction();
//	void JumpAction();
//	void MoveRight(float Val);
//	void MOveForWard(float Val);
//	void TurnAtRate(float Rate);
//	void LookUpAtRate(float Rate);
//
//	void StatusWindowOnOff();
//
//protected:
//	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//
//	void BeginPlay() override;
//
//private:
//
//	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//		class USpringArmComponent* SpringArmComponent;
//
//	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//		class UCameraComponent* CameraComponent;
//
//	void Tick(float _Delta) override;
//
//	UPROPERTY(Category = "Component", EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//		TMap<AIAniState, class UAnimMontage*> MapAnimation;
//
//	UFUNCTION()
//		void MontageEnd(UAnimMontage* Anim, bool _Inter);
//
//	UFUNCTION()
//		void AnimNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);
//
//	float Speed = 800.0f;
//
//	
//};
