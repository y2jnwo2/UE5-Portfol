// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalGameInstance/WeaponComponent.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<UActorComponent*> Components = GetOwner()->GetComponentsByTag(UStaticMeshComponent::StaticClass(), TEXT("WeaponMesh"));

	if (0 >= Components.Num())
	{
		return;
	}

	WeaponComponent = Cast<UStaticMeshComponent>(Components[0]);
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponComponent::ChangeWeaponAdd()
{
	if (nullptr == WeaponComponent)
	{
		return;
	}


	if (0 >= ArrWeaponMeshs.Num())
	{
		return;
	}

	++WeaponIndex;
	if (ArrWeaponMeshs.Num() <= WeaponIndex)
	{
		WeaponIndex = 0;
	}

	WeaponComponent->SetStaticMesh(ArrWeaponMeshs[WeaponIndex]);
}

void UWeaponComponent::ChangeWeapon(UStaticMesh* _Mesh)
{
	if (nullptr == WeaponComponent)
	{
		return;
	}

	WeaponComponent->SetStaticMesh(_Mesh);
}

void UWeaponComponent::ChangeWeaponIndex(int _Index)
{
	if (_Index >= ArrWeaponMeshs.Num())
	{
		return;
	}

	WeaponIndex = _Index;
	WeaponComponent->SetStaticMesh(ArrWeaponMeshs[WeaponIndex]);
}

