// Fill out your copyright notice in the Description page of Project Settings.


#include "WarZhaoGlobal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "War_UserWidget.h"

class UWar_UserWidget* UWarZhaoGlobal::DebugWidget = nullptr;

void UARGlobal::WarDebugTextInit()
{
	// �������� �ڵ����� ����������
	// delete�� �Ѵٰ� 
	DebugWidget = nullptr;
}

//static void UARGlobal::WarDebugTextPring(clas AActor* _Object, const FString& _Text)
//{
//	// ���⼭ ���� ������ ���ٸ�
//	// ����� ���� �Ѵ�.
//	// ������ ����.
//	if (nullptr == DebugWidget)
//	{
//		UWorld* World = _AActor->GetWorld();
//
//		if (nullptr == World && false == World->IsValidLowLevel())
//		{
//			return;
//		}
//
//		// 
//
//		// �̰� ��Ÿ�� �߰��� �˾Ƴ��� �����
//
//		FSoftClassPath ObjectClass("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/Global/WBP_GlobalDebug.WBP_GlobalDebug_C'");
//		TSubclassOf<UUserWidget> SubClassValue = ObjectClass.TryLoadClass<UUserWidget>();
//
//		if (nullptr == SubClassValue)
//		{
//			return;
//		}
//
//		UUserWidget* NewWidGet = CreateWidget<UUserWidget>(World, SubClassValue);
//
//		if (nullptr == NewWidGet)
//		{
//			// ������ �����Ҷ��� ������ �����Ƿ� �̰͵� ó�����ش�.
//			return;
//		}
//
//		DebugWidget = Cast<UWar_UserWidget>(NewWidGet);
//		DebugWidget->AddToViewport(1000);
//	}
//
//	DebugWidget->AddDebugText(_Text);
//}