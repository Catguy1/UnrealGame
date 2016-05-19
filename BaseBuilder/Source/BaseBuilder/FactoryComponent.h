// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseBuilderPlayerController.h"
#include "Components/ActorComponent.h"
#include "FactoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASEBUILDER_API UFactoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFactoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	float Timer;

	UPROPERTY(VisibleAnywhere)
		int ResourceAmount;
};
