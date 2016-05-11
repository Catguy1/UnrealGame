// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "BaseBuilding.h"
#include "GameFramework/PlayerController.h"
#include "BaseBuilderPlayerController.generated.h"

UCLASS()
class ABaseBuilderPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABaseBuilderPlayerController();

	UPROPERTY(EditAnywhere)
	AActor *ItemToPlace;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


