#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleStructure.generated.h"

UCLASS()
class ALIENVPREDATOR_API ADestructibleStructure : public AActor
{
	GENERATED_BODY()
	public:

	ADestructibleStructure();

	protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Destructible")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Destructible")
	UStaticMeshComponent* StructureMesh;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Destructible")
	void ApplyDamage(float DamageAmount);

private:
	void DestroyStructure();
};