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
	UFUNCTION(BlueprintCallable, Category = "SSFunctions")
	void ResetGame();

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int32 overlappingPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int32 spawnedPlayers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int32 enemiesToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int32 enemiesSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	int32 timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	FText text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SSVariables")
	FVector startPos;
	   
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Setters
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
		void SetSpawnedPlayers(int32 value) { spawnedPlayers += value; }
};
