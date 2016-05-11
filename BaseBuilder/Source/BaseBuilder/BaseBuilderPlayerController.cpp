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

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}

	FVector MoveVector = FVector(GetInputAxisValue("MoveForward") * 10, GetInputAxisValue("MoveRight") * 10, 0);

	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + MoveVector);
}

void ABaseBuilderPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ABaseBuilderPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ABaseBuilderPlayerController::OnSetDestinationReleased);

	InputComponent->BindAxis("MoveForward");
	InputComponent->BindAxis("MoveRight");
}

void ABaseBuilderPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ABaseBuilderPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}

	FTransform location = FTransform(DestLocation);


		GetWorld()->SpawnActor<ABaseBuilding>(DestLocation, FRotator(0));

}

void ABaseBuilderPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ABaseBuilderPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
