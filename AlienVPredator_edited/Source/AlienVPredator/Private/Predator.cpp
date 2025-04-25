// Copyright Rohit VFS 2023-2024


#include "Predator.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"

APredator::APredator()
{
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.0f;
	FireThreshold = 50.0f;
	FireDirection = FVector(1, 0, 0);
}

void APredator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckFireThreshold();
}

void APredator::TakeLivingDamage_Implementation()
{
}

void APredator::CheckFireThreshold() const
{
	if (Health <= FireThreshold)
	{
		FireAtAliens();
	}
}

void APredator::OnAlienHit(bool bIsGoo, float GooSpeed)
{
	
}

void APredator::FireAtAliens() const
{
	if (ProjectileClass)
	{
		FVector SpawnLocation = GetActorLocation() + FireDirection * 100.0f;
		FRotator SpawnRotation = FRotator::ZeroRotator;

		AProjectile* NewProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);

		if (NewProjectile)
		{
			NewProjectile->Direction = FireDirection;
		}
	}
}

