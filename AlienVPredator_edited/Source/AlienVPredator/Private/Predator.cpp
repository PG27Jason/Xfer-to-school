// Copyright Rohit VFS 2023-2024


#include "Predator.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

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
	Health -= 10.0f;  // Apply damage
	if (Health <= 0.0f)
	{
		Destroy();
	}
}

void APredator::OnAlienHit(bool bIsGoo, float GooSpeed)
{
	if (bIsGoo)
	{
		Health -= GooSpeed * 0.1f;
		if (Health <= 0.0f)
		{
			Destroy();
		}
	}
}

void APredator::CheckFireThreshold()
{
	const float currentHealth = Health;
	if (currentHealth <= FireThreshold)
	{
		FireAtAliens();
	}
}

void APredator::FireAtAliens()
{
	if (ProjectileClass && GetWorld())
	{
		FVector SpawnLocation = GetActorLocation() + FireDirection * 100.0f;
		FRotator SpawnRotation = FRotator::ZeroRotator;

		AProjectile* NewProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);

		if (NewProjectile)
		{
			NewProjectile->Direction = FireDirection;
			NewProjectile->PredatorOwner = this;
			NewProjectile->OnProjectileHit.AddDynamic(this, &APredator::OnProjectileHit);
		}
	}
}

void APredator::OnProjectileHit(AProjectile* Projectile)
{
	
}

