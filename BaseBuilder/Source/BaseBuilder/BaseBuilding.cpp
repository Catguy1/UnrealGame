// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BaseBuilding.h"
#include "BasePawn.h"


// Sets default values
ABaseBuilding::ABaseBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	if (StaticMesh.Object)
	{
		CubeMesh->SetStaticMesh(StaticMesh.Object);

		CubeMesh->bHiddenInGame = false;

		CubeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		RootComponent = CubeMesh;
	}
	static ConstructorHelpers::FClassFinder<ABasePawn>ObjectToSpawn(TEXT("Blueprint'/Game/TopDownCPP/Blueprints/BPBasePawn'"));

	if (ObjectToSpawn.Class)
	{
		SpawnPawn = (UClass*)ObjectToSpawn.Class;
	}

	SpawnTime = 5;

	Timer = SpawnTime;

	Spawning = true;
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Spawning)
	{
		if (Timer <= 0)
		{
			Spawn();
			Timer = SpawnTime;
		}
		else
		{
			Timer -= DeltaTime;
		}
	}
}

void ABaseBuilding::Spawn()
{
	/*FActorSpawnParameters SpawnParameter;
	SpawnParameter.Owner = this;
	SpawnParameter.Instigator = Instigator;*/

	ABasePawn *spawn = GetWorld()->SpawnActor<ABasePawn>(SpawnPawn, GetActorLocation() + FVector(100, 100, 100), GetActorRotation());

	ABaseBuilderPlayerController *controller = Cast<ABaseBuilderPlayerController>(GetWorld()->GetFirstPlayerController());

	spawn->Initialize(controller->EnemyBase, 1);
}

