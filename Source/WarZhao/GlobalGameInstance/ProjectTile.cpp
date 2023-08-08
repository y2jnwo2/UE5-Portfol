// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectTile.h"

AProjectTile::AProjectTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetCollisionProfileName(TEXT("NoCollision"), true);
	SphereComponent->ComponentTags.Add(FName("Damage"));
}

// Called when the game starts or when spawned
void AProjectTile::BeginPlay()
{
	Super::BeginPlay();

	OnDestroyed.AddDynamic(this, &AProjectTile::DestroyProjectile);
	// SphereComponent->SetCollisionProfileName(TEXT("MonsterAttack"), true);
}

void AProjectTile::DestroyProjectile(AActor* _Destroy)
{
	if (nullptr == DeathCreateObject)
	{
		return;
	}

	AActor* Actor = GetWorld()->SpawnActor<AActor>(DeathCreateObject);

	Actor->SetActorLocation(GetActorLocation());
	Actor->SetActorRotation(GetActorRotation());
}

// DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(AActor*, DestroyedActor);

// Called every frame
void AProjectTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	deathTime -= DeltaTime;

	if (deathTime < 0.0f)
	{
		Destroy();
		return;
	}

	AddActorWorldOffset(GetActorForwardVector() * DeltaTime * speed);

}


