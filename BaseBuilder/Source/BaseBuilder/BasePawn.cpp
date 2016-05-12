// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BasePawn.h"
#include "AI/Navigation/NavigationSystem.h"

// Sets default values
ABasePawn::ABasePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	CubeMesh->SetStaticMesh(StaticMesh.Object);

	CubeMesh->bHiddenInGame = false;

	CubeMesh->SetSimulatePhysics(true);

	CubeMesh->SetEnableGravity(true);

	RootComponent = CubeMesh;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));

	CubeMesh->BodyInstance.bLockXRotation = true;
	CubeMesh->BodyInstance.bLockYRotation = true;

	MoveComponent = CreateDefaultSubobject<UPawnMovementComponent>(TEXT("MoveComponent"));

	//MoveComponent->UpdatedComponent = RootComponent;
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
	UE_LOG(LogTemp, Warning, TEXT("Attempting to move"));
	if (Target != nullptr)
	{
		APawn* const Pawn = this;
		if (Pawn != nullptr)
		{
			UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();

			if (NavSys != nullptr)
			{
				NavSys->SimpleMoveToActor(this->Controller, DestActor);
				//NavSys->SimpleMoveToLocation(this->Controller, DestActor->ActorToWorld().GetLocation());
			}
			else
				UE_LOG(LogTemp, Warning, TEXT("No Navsystem"));
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("No Pawn"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("No Target"));
}