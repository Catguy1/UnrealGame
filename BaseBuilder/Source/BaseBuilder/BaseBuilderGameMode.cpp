// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BaseBuilder.h"
#include "BaseBuilderGameMode.h"
#include "BaseBuilderPlayerController.h"
#include "BaseBuilderCharacter.h"

ABaseBuilderGameMode::ABaseBuilderGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABaseBuilderPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}