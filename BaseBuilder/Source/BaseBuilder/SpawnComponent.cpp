// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "SpawnComponent.h"


// Sets default values for this component's properties
USpawnComponent::USpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	//static ConstructorHelpers::FClassFinder<ABasePawn>ObjectToSpawn(TEXT("Blueprint'/Game/TopDownCPP/Blueprints/BPBasePawn'"));

	//if (ObjectToSpawn.Class)
	//{
	//	SpawnPawn = (UClass*)ObjectToSpawn.Class;
	//}

	// ...
}


// Called when the game starts
void USpawnComponent::BeginPlay()
{
	Super::BeginPlay();

	Timer = SpawnTime;

	// ...

}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Timer <= 0)
	{
		Spawn();
		Timer = SpawnTime;
	}
	else
	{
		Timer -= DeltaTime;
	}

	// ...
}

void USpawnComponent::Spawn()
{
	if (SpawnPawn != nullptr)
	{
		ABasePawn *spawn = GetOwner()->GetWorld()->SpawnActor<ABasePawn>(SpawnPawn, GetOwner()->GetActorLocation() + FVector(0, 0, 100), GetOwner()->GetActorRotation());

		ABaseBuilderPlayerController *controller = Cast<ABaseBuilderPlayerController>(GetWorld()->GetFirstPlayerController());

		spawn->Initialize(controller->EnemyBase, 1);
	}
}

