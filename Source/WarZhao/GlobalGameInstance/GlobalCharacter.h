// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GlobalAnimInstance.h"
#include "GlobalCharacter.generated.h"

UCLASS()
class WARZHAO_API AGlobalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGlobalCharacter();

	void SetHP(int _HP)
	{
		HP -= _HP;
	}

	void AddHP(int _HP)
	{
		HP += _HP;
	}

	int GetHP()
	{
		return HP;
	}

	int GetAniState()
	{
		return AniState;
	}

	template<typename EnumType>
	EnumType GetAniState()
	{
		return static_cast<EnumType>(AniState);
	}

	template<typename EnumType>
	void SetAniState(EnumType _AniState)
	{
		AniState = static_cast<int>(_AniState);
	}

	void SetAniState(int _AniState)
	{
		AniState = _AniState;
	}

	class UGlobalAnimInstance* GetGlobalAnimInstance()
	{
		return GlobalAnimInstance;
	}

	template<typename EnumType>
	class UAnimMontage* GetAnimMontage(EnumType _Index)
	{
		return GetAnimMontage(static_cast<int>(_Index));
	}

	class UAnimMontage* GetAnimMontage(int _Index)
	{
		if (false == AllAnimations.Contains(_Index))
		{
			return nullptr;
		}
		return AllAnimations[_Index];
	}

	template<typename EnumType>
	void SetAllAnimation(const TMap<EnumType, class UAnimMontage*>& _MapAnimation)
	{
		for (TPair<EnumType, UAnimMontage*> Pair : _MapAnimation)
		{
			AllAnimations.Add(static_cast<int>(Pair.Key), Pair.Value);
		}
	}

	UFUNCTION()
	void PushComponent(UActorComponent* _Component)
	{
		MgrComponent.Add(_Component);
	}
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
		float BaseLookUpRate;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	template<typename EnumType>
	void PushAnimation(EnumType _Index, class UAnimMontage* _Montage)
	{
		PushAnimation(static_cast<int>(_Index), _Montage);
	}

	void PushAnimation(int _Index, class UAnimMontage* _Montage)
	{
		if (true == AllAnimations.Contains(_Index))
		{
			return;
		}

		AllAnimations.Add(_Index, _Montage);
	}


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OverLap(class UPrimitiveComponent* OverlappedComponent,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherCOmpr,
			int32 OtherBOdyIndex,
			bool bFromSweep, const FHitResult& SweepResult);


	virtual void Damage(AActor* _Actor) {}

	UPROPERTY(Category = "GlobalCharacterValue", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<UActorComponent*> MgrComponent;
	
	// �˹�
	virtual void LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride) override;

	UPROPERTY(EditAnyWhere,Category = "Force")
	float KnockBackForce = 500.f;

	UCharacterMovementComponent* CharacterMovement;
private:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "GlobalCharacterValue", EditAnywhere, BluePrintReadWrite, meta = (AllowPrivateAccess = true))
	int AniState = 0;
	
	UPROPERTY(Category = "GlobalCharacterValue", EditAnywhere, BluePrintReadWrite, meta = (AllowPrivateAccess = true))
	TMap<int, class UAnimMontage*> AllAnimations;

	class UGlobalAnimInstance* GlobalAnimInstance = nullptr;

	UPROPERTY(Category = "GlobalCharacterValue", EditAnywhere, BluePrintReadWrite, meta = (AllowPrivateAccess = true))
	float HP = 1;

	UPROPERTY(Category = "GlobalCharacterValue", EditAnywhere, BluePrintReadWrite, meta = (AllowPrivateAccess = true))
	float MAXHP = 10;
};
