// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WARZHAO_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UWeaponComponent();

	UFUNCTION(BluePrintCallable)
	void ChangeWeapon(UStaticMesh* _Mesh);

	UFUNCTION(BluePrintCallable)
	void ChangeWeaponAdd();

	UFUNCTION(BluePrintCallable)
	void ChangeWeaponIndex(int _Index);

protected:

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UStaticMeshComponent* WeaponComponent;

	UPROPERTY(Category = "Mesh", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	TArray<UStaticMesh*> ArrWeaponMeshs;

	int WeaponIndex;
};
