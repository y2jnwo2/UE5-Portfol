// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

AGameHUD::AGameHUD()
{

}

AGameHUD::~AGameHUD()
{

}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	// ���� �����ϴ� �������Ʈ�� ���۷����� ��θ� �������� ����� �Ʒ��� ����.
	FSoftClassPath ClassPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/UIEx/WBP_UIEx.WBP_UIEx_C'"));
	TSubclassOf<UUserWidget> MainWidgetClass = ClassPath.TryLoadClass<UUserWidget>();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
	MainWidget = Cast<UMainWidget>(Widget);
	MainWidget->AddToViewport();
	//{
	//	UUserWidget* Window = Cast<UUserWidget>(MainWidget->GetWidgetFromName(TEXT("TalkTextWindow")));

	//	// Window->SetVisibility(ESlateVisibility::Hidden);
	//	// Window->Visibility = ESlateVisibility::Visible;


	//}

	{
		UUserWidget* Window = Cast<UUserWidget>(MainWidget->GetWidgetFromName(TEXT("StatusWindow")));
	}

}

void AGameHUD::Tick(float _Delta)
{
	Super::Tick(_Delta);

	// /Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UIEx/WBP_UIEX.WBP_UIEX'
}