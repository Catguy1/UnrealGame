// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BaseBuilder.h"
#include "BaseBuilderPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

ABaseBuilderPlayerController::ABaseBuilderPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	Money = 100;
}

void ABaseBuilderPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ABaseBuilderPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ABaseBuilderPlayerController::OnClick);
}

void ABaseBuilderPlayerController::OnClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Attempting to spawn a thing"));

	if (SelectedBuilding != nullptr)
	{
		ABaseBuilding *b = SelectedBuilding->GetDefaultObject<ABaseBuilding>();

		if (b != nullptr && Money >= b->Price)
		{
			//Getting the position of the mouse and spawning a building at that point
			FHitResult Hit;
			GetHitResultUnderCursor(ECC_Visibility, false, Hit);

			if (Hit.GetActor() != nullptr)
			{
				if (Hit.GetComponent()->ComponentHasTag("PlayerArea"))// && Hit.GetActor()->StaticClass() != SelectedBuilding->GetClass())
				{
					ABaseBuilding *Spawn = Cast<ABaseBuilding>(GetWorld()->SpawnActor<AActor>(SelectedBuilding, Hit.ImpactPoint - FVector(0, 0, -50), FRotator(0)));

					Spawn->SetFaction(1);

					Money -= Spawn->Price;
				}
			}
		}
	}
}
