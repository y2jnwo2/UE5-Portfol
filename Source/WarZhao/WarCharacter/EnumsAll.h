#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class WarAniState : uint8
{
	None UMETA(DisplayName = "������"),
	Idle UMETA(DisplayName = "���ֱ�"),
	LeftMove UMETA(DisplayName = "�����̵�"),
	RightMove UMETA(DisplayName = "�������̵�"),
	ForwardMove UMETA(DisplayName = "�������̵�"),
	BackwardMove UMETA(DisplayName = "�ڷ��̵�"),
	Jump UMETA(DisplayName = "����"),
	Attack UMETA(DisplayName = "����"),
};