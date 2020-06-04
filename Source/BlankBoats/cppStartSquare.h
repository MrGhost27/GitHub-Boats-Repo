// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "cppStartSquare.generated.h"

class UTextRenderComponent;

UCLASS()
class BLANKBOATS_API AcppStartSquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcppStartSquare();

	UTextRenderComponent* textRender;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Functions
	UFUNCTION(BlueprintCallable, Category = "SSFunctions")
	bool UpdateTimer();
	//UFUNCTION(BlueprintCallable, Category = "SSFunctions")
	//void SpawnEnemies();

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int overlappingPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int spawnedPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int enemiesToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int enemiesSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	FText text;
	   
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
