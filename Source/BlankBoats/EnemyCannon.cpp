// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCannon.h"

// Sets default values
AEnemyCannon::AEnemyCannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Box"));
	CollisionMesh->SetBoxExtent(FVector(32.f, 32.f, 96.f));

	//GameMode = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
}

// Called when the game starts or when spawned
void AEnemyCannon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

