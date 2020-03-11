// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameModeBase.h"
#include "Components/BoxComponent.h"
#include "EnemyCannon.generated.h"

UCLASS()
class BLANKBOATS_API AEnemyCannon : public AActor
{
	GENERATED_BODY()

	//class AMyGameMode;

public:	
	// Sets default values for this actor's properties
	AEnemyCannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AGameModeBase* MyGameMode = nullptr;
	UBoxComponent* CollisionMesh = nullptr;
	
	//AMyGameMode* GameMode = nullptr; // Can't have a reference to a blueprint.

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
