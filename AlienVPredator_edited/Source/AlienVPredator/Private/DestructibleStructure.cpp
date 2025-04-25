#include "C:\Users\TheSa\Downloads\AlienVPredator\AlienVPredator\Intermediate\Build\Win64\x64\AlienVPredatorEditor\Development\UnrealEd\SharedPCH.UnrealEd.Project.NoValFmtStr.ValApi.Cpp20.InclOrderUnreal5_3.h"
#include "DestructibleStructure.h"
#include "Components/StaticMeshComponent.h"

ADestructibleStructure::ADestructibleStructure()
{
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.0f;

	StructureMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StructureMesh"));
	SetRootComponent(StructureMesh);
}

void ADestructibleStructure::BeginPlay()
{
	Super::BeginPlay();
}

void ADestructibleStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADestructibleStructure::ApplyDamage(float DamageAmount)
{
	Health -= DamageAmount;
	if (Health <= 0.0f)
	{
		DestroyStructure();
	}
}

void ADestructibleStructure::DestroyStructure()
{
	Destroy();
}