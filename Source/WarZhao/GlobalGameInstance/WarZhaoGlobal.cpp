// Fill out your copyright notice in the Description page of Project Settings.


#include "WarZhaoGlobal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "War_UserWidget.h"

class UWar_UserWidget* UWarZhaoGlobal::DebugWidget = nullptr;
FRandomStream UWarZhaoGlobal::MainRandom;

void UWarZhaoGlobal::WarDebugTextInit()
{
	
	DebugWidget = nullptr;
}

void UWarZhaoGlobal::WarDebugTextPrint(class AActor* _AActor, const FString& _Text)
{
	// 여기서 만약 위젯이 없다면
	// 만들어 내야 한다.
	// 위젯이 없어.
	if (nullptr == DebugWidget)
	{
		UWorld* World = _AActor->GetWorld();

		if (nullptr == World && false == World->IsValidLowLevel())
		{
			return;
		}

		// 

		// 이걸 런타임 중간에 알아내는 방법은

		FSoftClassPath ObjectClass("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/Global/WBP_WarWidget.WBP_WarWidget'_C'");
		TSubclassOf<UUserWidget> SubClassValue = ObjectClass.TryLoadClass<UUserWidget>();

		if (nullptr == SubClassValue)
		{
			return;
		}

		UUserWidget* NewWidGet = CreateWidget<UUserWidget>(World, SubClassValue);

		if (nullptr == NewWidGet)
		{
			// 생성에 실패할때까 있을수 있으므로 이것도 처리해준다.
			return;
		}

		DebugWidget = Cast<UWar_UserWidget>(NewWidGet);
		DebugWidget->AddToViewport(1000);
	}

	DebugWidget->AddDebugText(_Text);
}