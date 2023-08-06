// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class AIState : uint8
{
	None UMETA(DisplayName = "사용안함"),
	Idle UMETA(DisplayName = "서있기"),
	LeftMove UMETA(DisplayName = "왼쪽이동"),
	RightMove UMETA(DisplayName = "오른쪽이동"),
	ForwardMove UMETA(DisplayName = "앞으로이동"),
	BackwardMove UMETA(DisplayName = "뒤로이동"),
	Jump UMETA(DisplayName = "점프"),
	Attack UMETA(DisplayName = "공격"),
};

UENUM(BlueprintType)
enum class ItemType : uint8
{
	NONE UMETA(DisplayName = "내용없음"),
	ARMOR UMETA(DisplayName = "갑옷"),
	WEAPON UMETA(DisplayName = "무기"),
	POSTION UMETA(DisplayName = "포션"),
	QUEST UMETA(DisplayName = "퀘스트"),
};
