// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BaseBuilder.h"
#include "BaseBuilderPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

ABaseBuilderPlayerController::ABaseBuilderPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ABaseBuilderPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	FVector MoveVector = FVector(GetInputAxisValue("MoveForward") * 10, GetInputAxisValue("MoveRight") * 10, 0);

	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + MoveVector);
}

void ABaseBuilderPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ABaseBuilderPlayerController::OnClick);

	InputComponent->BindAxis("MoveForward");
	InputComponent->BindAxis("MoveRight");
}

void ABaseBuilderPlayerController::OnClick()
{
	//Getting the position of the mouse and spawning a building at that point
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.GetActor() != nullptr)
	{
		if (!Hit.GetActor()->IsA(ABaseBuilding::StaticClass()))
		{
			GetWorld()->SpawnActor<ABaseBuilding>(Hit.ImpactPoint - FVector(0, 0, -50), FRotator(0));
		}
	}
}
