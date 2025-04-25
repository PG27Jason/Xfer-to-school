#include "DestructibleStructure.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"

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