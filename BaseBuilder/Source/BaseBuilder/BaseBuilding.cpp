// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BaseBuilding.h"
#include "BasePawn.h"


// Sets default values
ABaseBuilding::ABaseBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Description = "Splany thing Here!";

}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ABaseBuilding::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (DamageCauser->GetClass() != GetClass())
	{
		const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
		if (ActualDamage > 0.f)
		{
			Health -= ActualDamage;
		}
		if (Health <= 0)
		{
			OnDeath();
		}
		return ActualDamage;
	}
	return 0;
}

void ABaseBuilding::OnDeath()
{
	GetWorld()->DestroyActor(this);
}

void ABaseBuilding::SetFaction(int i)
{
	TeamID = i;
}

