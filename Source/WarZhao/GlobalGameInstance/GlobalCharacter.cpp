// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance/GlobalCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AGlobalCharacter::AGlobalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGlobalCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GlobalAnimInstance = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());

	if (nullptr == GlobalAnimInstance)
	{
		return; 
	}
	GlobalAnimInstance->AllAnimations = AllAnimations;

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGlobalCharacter::OverLap);
}

// Called every frame
void AGlobalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGlobalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGlobalCharacter::OverLap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	

	if (true == OtherComp->ComponentHasTag(TEXT("Damage")))
	{
		
		FVector PlayerPos = OtherActor->GetActorLocation();
		AGlobalCharacter* Character = Cast<AGlobalCharacter>(SweepResult.GetActor());


		if (nullptr == Character)
		{
			return;
		}

		if (true == Character->ActorHasTag("Monster"))
		{
			//Character->SetActorLocation(FVector(Character->GetActorLocation().X, Character->GetActorLocation().Y, Character->GetActorLocation().Z + 50.f));

			FVector EnemyPos = Character->GetActorLocation();
			FVector Dist = (EnemyPos - PlayerPos);
			FVector NormalizedDist = Dist.GetSafeNormal();

			CharacterMovement = Character->GetCharacterMovement();

			if (CharacterMovement == nullptr)
			{
				return;
			}
			//CharacterMovement->AddImpulse(NormalizedDist * KnockBackForce, false);
			//Character->LaunchCharacter(NormalizedDist * KnockBackForce, false, false);

		}

		HP -= 3;
	}
	// HPRefresh();
}

// ³Ë¹é±¸Çö
void AGlobalCharacter::LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride)
{
	CharacterMovement = this->GetCharacterMovement();

	if (nullptr == this->CharacterMovement)
	{
		return;
	}
	if (this->CharacterMovement)
	{

		FVector FinalVel = LaunchVelocity;
		const FVector Velocity = GetVelocity();

		if (!bXYOverride)
		{
			FinalVel.X += Velocity.X;
			FinalVel.Y += Velocity.Y;
		}
		if (!bZOverride)
		{
			FinalVel.Z += Velocity.Z;
		}

		CharacterMovement->Launch(FinalVel);

		OnLaunched(LaunchVelocity, bXYOverride, bZOverride);
	}
}

