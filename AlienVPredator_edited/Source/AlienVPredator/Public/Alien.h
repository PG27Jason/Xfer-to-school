// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "Alien.generated.h"

/**
 * 
 */
class UStaticMeshComponent;
class UArrowComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAlienGooEvent, bool, isGoo, float, gooSpeed);

UCLASS()
class ALIENVPREDATOR_API AAlien : public ALivingOrganism
{
	GENERATED_BODY()


public:
	AAlien();

	UFUNCTION(BlueprintNativeEvent)
	void OnAlienHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UArrowComponent> ArrowComponent;

	UPROPERTY(BlueprintAssignable)
	FAlienGooEvent MyGooEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MovementSpeed;

	virtual void Tick(float deltaSeconds) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


private:

	void AddForceToBody() const;
	
};
