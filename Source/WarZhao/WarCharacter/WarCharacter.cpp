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

}

