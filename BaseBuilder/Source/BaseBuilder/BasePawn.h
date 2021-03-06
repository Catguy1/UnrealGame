// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class BASEBUILDER_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void Initialize(AActor *destination, int faction);

	UPROPERTY(BlueprintReadWrite)
		int Faction;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Firing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* BaseTarget;

private:
	void SetNewMoveDestination(const AActor* DestActor);

	float TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser);

	void OnDeath();


	UPROPERTY(Category = Meshes, VisibleAnywhere)
		UStaticMeshComponent *CubeMesh;

	virtual void Attack();
};
