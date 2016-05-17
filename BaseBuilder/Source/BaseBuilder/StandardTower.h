// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseBuilding.h"
#include "StandardTower.generated.h"

/**
 *
 */
UCLASS()
class BASEBUILDER_API AStandardTower : public ABaseBuilding
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStandardTower();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	void TargetEnemies();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector HitRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackTimer;

private:



	virtual void Attack();
};
