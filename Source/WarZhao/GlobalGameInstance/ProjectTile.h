// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ProjectTile.generated.h"

UCLASS()
class WARZHAO_API AProjectTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectTile();

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float speed = 2000.0f;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float deathTime = 5.0f;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> DeathCreateObject = nullptr;

	UFUNCTION()
		FORCEINLINE USphereComponent* GetSphereComponent()
	{
		return SphereComponent;
	}
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:	
	UFUNCTION()
		void DestroyProjectile(AActor* _Destroy);

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* SphereComponent = nullptr;
};
