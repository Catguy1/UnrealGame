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

	void Initialize(AActor *destination);

	// Called to bind functionality to input

	void SetNewMoveDestination(const AActor* DestActor);

	UPROPERTY(EditAnywhere)
		AActor* Target;

	UPROPERTY(Category = Meshes, VisibleAnywhere)
		UStaticMeshComponent *CubeMesh;

	//UPROPERTY(VisibleAnywhere)
	//	UPawnMovementComponent *MoveComponent;
};
