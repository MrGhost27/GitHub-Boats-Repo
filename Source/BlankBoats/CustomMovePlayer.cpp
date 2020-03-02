// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovePlayer.h"
#include "Classes/Components/StaticMeshComponent.h"

// Sets default values
ACustomMovePlayer::ACustomMovePlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Players Mesh");

	
}

// Called when the game starts or when spawned
void ACustomMovePlayer::BeginPlay()
{
	Super::BeginPlay();
	
	StaticMesh->SetWorldScale3D(FMath::VRand());
}

// Called every frame
void ACustomMovePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

