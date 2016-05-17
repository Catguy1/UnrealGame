// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "StandardTower.h"
#include "DrawDebugHelpers.h"

// Sets default values
AStandardTower::AStandardTower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
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
	FVector StartPoint = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);

	FRotator Rotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll);

	FVector EndPoint = StartPoint + (Rotation.Vector() * 200);

	TArray<FHitResult> HitResult = TArray<FHitResult>();

	//DrawDebugLine(GetWorld(), StartPoint, HitRange, FColor(255, 0, 0), true, -1.0f, 0, 10.0f);

	bool Hit = GetWorld()->LineTraceMultiByObjectType(HitResult, StartPoint, HitRange, FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn), FCollisionQueryParams("ActionTrace", false, GetOwner()));

	if (Hit)
	{
		for (int i = 0; i < HitResult.Num(); i++)
		{
			TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
			FDamageEvent DamageEvent(ValidDamageTypeClass);

			HitResult[i].Actor->TakeDamage(Damage, DamageEvent, NULL, this);

			AttackTimer = AttackSpeed;

		}
	}
}

void AStandardTower::TargetEnemies()
{

}
