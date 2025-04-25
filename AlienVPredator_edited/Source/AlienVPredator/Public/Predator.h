// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "DamageInterface.h"
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

	virtual void Tick(float DeltaTime) override;

	virtual void TakeLivingDamage_Implementation() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat")
	float Health;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat")
	float FireThreshold;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere)
	FVector FireDirection;

	UFUNCTION()
	static void OnAlienHit(bool bIsGoo, float GooSpeed);

private:
	void FireAtAliens() const;
	void CheckFireThreshold() const;
};
