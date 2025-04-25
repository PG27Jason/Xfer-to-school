// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "DamageInterface.h"
#include "Projectile.h"
#include "Predator.generated.h"

/**
 * 
 */
UCLASS()
class ALIENVPREDATOR_API APredator : public ALivingOrganism , public IDamageInterface
{
	GENERATED_BODY()

public:

	APredator();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void FireAtAliens();

	UFUNCTION()
	void OnProjectileHit(AProjectile* Projectile);

	UFUNCTION()
	void OnAlienHit(bool bIsGoo, float GooSpeed);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void CheckFireThreshold();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
	float Health;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat")
	float FireThreshold;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere)
	FVector FireDirection;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void TakeLivingDamage_Implementation() override;

private:
	void FireAtAliens() const;
	void CheckFireThreshold() const;
};
