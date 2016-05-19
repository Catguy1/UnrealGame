// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "StandardTower.h"
#include "DrawDebugHelpers.h"

// Sets default values
AStandardTower::AStandardTower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 200;
	AttackSpeed = 0.5;
	Damage = 5;

	Spawning = false;
}

// Called when the game starts or when spawned
void AStandardTower::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStandardTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AttackTimer -= DeltaTime;
	if (Firing)
	{
		Attack();
	}
}

float AStandardTower::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (DamageCauser->GetClass() != GetClass())
	{
		const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
		if (ActualDamage > 0.f)
		{
			Health -= ActualDamage;
		}

		return ActualDamage;
	}
	return 0;
}

void AStandardTower::Attack()
{
	if (Target != NULL)
	{
		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);

		Target->TakeDamage(Damage, DamageEvent, NULL, this);

		AttackTimer = AttackSpeed;
		Firing = false;
		//SpottedPawn = false;
	}
}
