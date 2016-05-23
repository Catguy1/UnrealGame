// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasePawn.h"
#include "BaseBuilderPlayerController.h"
#include "Components/ActorComponent.h"
#include "SpawnComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BASEBUILDER_API USpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USpawnComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		float SpawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBlueprint *SpawnPawn;

private:
	float Timer;

	void Spawn();

	UPROPERTY(EditAnywhere)
		bool Spawning;

};
