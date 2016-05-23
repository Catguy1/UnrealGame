// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BaseBuilderPlayerController.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "GameFramework/Actor.h"
#include "BaseBuilding.generated.h"

UCLASS()
class BASEBUILDER_API ABaseBuilding : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseBuilding();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(Category = Meshes, VisibleAnywhere)
		UStaticMeshComponent *CubeMesh;

	UPROPERTY(VisibleAnywhere)
		int TeamID;

	UPROPERTY(EditAnywhere)
		int Price;

	void SetFaction(int i);
};
