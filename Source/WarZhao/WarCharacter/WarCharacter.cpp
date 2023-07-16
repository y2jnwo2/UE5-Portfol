// Fill out your copyright notice in the Description page of Project Settings.


#include "WarCharacter.h"

// Sets default values
AWarCharacter::AWarCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;*/

	JumpMaxHoldTime = 0.0f;

}

// Called when the game starts or when spawned
void AWarCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//static bool bBindingsAdded = false;
	//if (!bBindingsAdded)
	//{
	//	bBindingsAdded = true;

	//	// ������ ������ ����?
	//	// DefaultPawn_MoveForward �߰��Ǵ°� ��
	//	// ����θ� �ϰ� �ֽ��ϴ�.
	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerMoveForward", EKeys::W, 1.f));
	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerMoveForward", EKeys::S, -1.f));

	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerMoveRight", EKeys::A, -1.f));
	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerMoveRight", EKeys::D, 1.f));

	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerTurn", EKeys::MouseX, 1.f));

	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerLookUp", EKeys::MouseY, -1.f));

	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerLookUp", EKeys::MouseY, -1.f));

	//	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("PlayerJumpAxis", EKeys::E, -1.f));


	//	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping(TEXT("PlayerAttack"), EKeys::LeftMouseButton));
	//	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping(TEXT("PlayerJumpAction"), EKeys::SpaceBar));
	//}

	//// Ű�� �Լ��� �����մϴ�.
	//// �� Ű�� ������ �� �Լ��� ����������ε�.
	//// ���϶��� �ϴ� ��� ���������.
	//PlayerInputComponent->BindAxis("PlayerMoveForward", this, &AWarCharacter::MoveForward);
	//PlayerInputComponent->BindAxis("PlayerMoveRight", this, &AWarCharacter::MoveRight);
	//PlayerInputComponent->BindAxis("PlayerTurn", this, &AWarCharacter::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("PlayerTurnRate", this, &AWarCharacter::TurnAtRate);
	//PlayerInputComponent->BindAxis("PlayerLookUp", this, &AWarCharacter::AddControllerPitchInput);
	//PlayerInputComponent->BindAxis("PlayerLookUpRate", this, &AWarCharacter::LookUpAtRate);
	//PlayerInputComponent->BindAxis("PlayerJumpAxis", this, &AWarCharacter::JumpAxis);

	//PlayerInputComponent->BindAction("PlayerAttack", EInputEvent::IE_Pressed, this, &AWarCharacter::AttackAction);
	//PlayerInputComponent->BindAction("PlayerJumpAction", EInputEvent::IE_Pressed, this, &AWarCharacter::JumpAction);
}

//void AWarCharacter::MoveRight(float Val)
//{
//	if (AniState == TPSAniState::Attack || AniState == TPSAniState::Jump)
//	{
//		return;
//	}
//
//	if (Val != 0.f)
//	{
//		if (Controller)
//		{
//			FRotator const ControlSpaceRot = Controller->GetControlRotation();
//			// transform to world space and add it
//			// ���� �� ȸ���� �����ͼ� y�࿡ �ش��ϴ� �຤�͸� ������ �̴ϴ�.
//			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
//
//			AniState = Val > 0.f ? TPSAniState::RightMove : TPSAniState::LeftMove;
//			return;
//		}
//	}
//	else
//	{
//		if (AniState == TPSAniState::RightMove || AniState == TPSAniState::LeftMove)
//		{
//			AniState = TPSAniState::Idle;
//		}
//	}
//}
//
//void AWarCharacter::MoveForward(float Val)
//{
//	if (AniState == TPSAniState::Attack || AniState == TPSAniState::Jump)
//	{
//		return;
//	}
//
//	if (Val != 0.f)
//	{
//		if (Controller)
//		{
//			// ��Ʈ�ѷ��� �⺻������
//			// charcter �ϳ��� �پ� �ֽ��ϴ�.
//			FRotator const ControlSpaceRot = Controller->GetControlRotation();
//
//			// �̰� ������ ���Դϴ�.
//			// transform to world space and add it
//			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
//			// ž������̸� �ٸ��� ������ �Ǵµ�.
//			// ������ TPS�� �ϰ� �ֱ� ������ ��Ʈ�ѷ��� ȸ���̳� ������ ȸ���̳� ���ƿ�.
//			// AddMovementInput(GetActorForwardVector(), Val);
//
//			AniState = Val > 0.f ? TPSAniState::ForwardMove : TPSAniState::BackwardMove;
//			return;
//		}
//	}
//	else
//	{
//		if (AniState == TPSAniState::ForwardMove || AniState == TPSAniState::BackwardMove)
//		{
//			AniState = TPSAniState::Idle;
//		}
//	}
//
//	// �̷� ������ �Լ� �� static�Լ��� �ǹ��Ѵ�.
//	// AEGLOBAL::DebugPrint("AAAAAAA");
//}
//
//
//void AWarCharacter::TurnAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
//}
//
//void AWarCharacter::LookUpAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
//}
//
//
//void AWarCharacter::JumpAxis(float Rate)
//{
//	if (0.0f == Rate)
//	{
//		if (true == AxisJump)
//		{
//			StopJumping();
//			AxisJump = false;
//		}
//		return;
//	}
//
//	AxisJump = true;
//	Jump();
//}
//
//void AWarCharacter::JumpAction()
//{
//	// JumpCurrentCount
//	UE_LOG(LogTemp, Log, TEXT("%S(%u)> %d"), __FUNCTION__, __LINE__, JumpCurrentCount);
//	Jump();
//
//	AniState = TPSAniState::Jump;
//}
//
//void AWarCharacter::AttackAction()
//{
//	// �����Ʈ ������Ʈ�� ���ؼ� �Ѵ�.
//	// GetMovementComponent()
//
//	// PlayMontage();
//
//	AniState = TPSAniState::Attack;
//}
//
//void AWarCharacter::AnimationTick()
//{
//	//class UAnimMontage* Montage = AllAnimations[AniState];
//
//	//if (nullptr == Montage)
//	//{
//	//	return;
//	//}
//
//	//if (false == GetMesh()->GetAnimInstance()->Montage_IsPlaying(Montage))
//	//{
//	//	GetMesh()->GetAnimInstance()->Montage_Play(Montage, 1.0f);
//	//}
//}

