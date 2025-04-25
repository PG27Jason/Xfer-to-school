// Copyright Rohit VFS 2023-2024


#include "MyLivingOrganismSpawner.h"
#include "LivingOrganism.h"

// Sets default values
AMyLivingOrganismSpawner::AMyLivingOrganismSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	SpawnDelay = 3.0f;
	SpawnHandle.Invalidate();
}

void AMyLivingOrganismSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorldTimerManager().ClearTimer(SpawnHandle);
}

// Called when the game starts or when spawned
void AMyLivingOrganismSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnHandle, this, &AMyLivingOrganismSpawner::SpawnLivingOrganism, SpawnDelay, true);
	
}

void AMyLivingOrganismSpawner::SpawnLivingOrganism()
{
	if (!IsValid(ClassToSpawn))
	{
		UE_LOG(LogTemp, Warning, TEXT("ClassToSpawn is not valid"));
		return;
	}

	FActorSpawnParameters MySpawnParams;
	MySpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if (AActor* NewActor = GetWorld()->SpawnActor<ALivingOrganism>(ClassToSpawn, GetActorLocation(), GetActorForwardVector().Rotation(), MySpawnParams))
	{
		// Spawn successful
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to spawn actor"));
	}
}

// Called every frame
void AMyLivingOrganismSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

