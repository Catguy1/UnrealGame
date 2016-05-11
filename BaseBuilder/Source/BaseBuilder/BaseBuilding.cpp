// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BaseBuilding.h"


// Sets default values
ABaseBuilding::ABaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	
	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	CubeMesh->SetStaticMesh(StaticMesh.Object);

	CubeMesh->bHiddenInGame = false;

	RootComponent = CubeMesh;
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseBuilding::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
