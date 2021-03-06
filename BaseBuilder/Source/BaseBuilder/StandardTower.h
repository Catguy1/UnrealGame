// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseBuilding.h"
#include "StandardTower.generated.h"

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APawn* Target;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Firing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SpottedPawn;

private:
	virtual void Attack();
};
