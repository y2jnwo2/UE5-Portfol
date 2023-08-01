// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalAnimInstance.h"
#include "GlobalCharacter.h"
//#include "Global/Data/MonsterData.h"
#include "WarZhaoGlobal.h"

void UGlobalAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OnMontageBlendIngOut.AddDynamic(this, &UGlobalAnimInstance::MontageEnd)
}

void UGlobalAnimInstance::NativeUpdateAnimation(float _DeltaTime)
{

}