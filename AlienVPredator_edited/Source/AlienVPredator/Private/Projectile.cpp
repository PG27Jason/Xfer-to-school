#include "Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/Engine.h"
#include "DamageInterface.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CollisionComponent);
	
	SetRootComponent(CollisionComponent);

	MovementSpeed = 2000.0f;
	Direction = FVector(1, 0, 0);
	PredatorOwner = nullptr;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	const FVector Velocity = Direction * MovementSpeed;
	MeshComponent->SetPhysicsLinearVelocity(Velocity);
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(this))
	{
		if (OtherActor && OtherActor->Implements<UDamageInterface>())
		{
			IDamageInterface::Execute_TakeLivingDamage(OtherActor);
			this->DealDamage(OtherActor);
		}
		Destroy();
	}
}

void AProjectile::DealDamage(AActor* HitActor)
{
	if (HitActor)
	{
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red, FString::Printf(TEXT("Hit Actor: %s"), *HitActor->GetName()));
	}
}
