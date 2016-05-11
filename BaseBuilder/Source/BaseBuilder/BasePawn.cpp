// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BasePawn.h"
#include "AI/Navigation/NavigationSystem.h"

// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetNewMoveDestination(Target);
}

void ABasePawn::SetNewMoveDestination(const AActor* DestActor)
{
	APawn* const Pawn = this;
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestActor->ActorToWorld().GetLocation(), Pawn->GetActorLocation());

		//// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
		NavSys->SimpleMoveToActor(this->Controller, DestActor);
		//NavSys->SimpleMoveToLocation(this->Controller, DestActor->ActorToWorld().GetLocation());
		}
	}
}