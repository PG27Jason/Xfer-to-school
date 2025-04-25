#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProjectileHitDelegate, AProjectile*, Projectile);

UCLASS()
class ALIENVPREDATOR_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	AProjectile();
	

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Projectile")
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="Projectile")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	FVector Direction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectile")
	class APredator* PredatorOwner;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	static void DealDamage(AActor* HitActor);

	UPROPERTY(BlueprintAssignable)
	FProjectileHitDelegate OnProjectileHit;
	
};
