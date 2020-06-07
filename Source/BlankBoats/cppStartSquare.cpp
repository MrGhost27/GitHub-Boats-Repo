// Fill out your copyright notice in the Description page of Project Settings.


#include "cppStartSquare.h"
#include "PlayerCharacter.h"

// Sets default values
AcppStartSquare::AcppStartSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Variables
	overlappingPlayers = 0;
	spawnedPlayers = 0;
	enemiesToSpawn = 5;
	enemiesSpawned = 0;
	timer = 0;
	text = FText::FromString("Start");
}

// Called when the game starts or when spawned
void AcppStartSquare::BeginPlay()
{
	Super::BeginPlay();

	//Set References
	textRender = AActor::FindComponentByClass<UTextRenderComponent>();
}

// Called every frame
void AcppStartSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AcppStartSquare::UpdateTimer() {
	if (spawnedPlayers > 0 && overlappingPlayers == spawnedPlayers) { //Check that at least 1 player is spawned and all spawned players are withing the start square
		timer++; //Increment timer

		//Format Timer Text
		FString sTimer = FString::FromInt(500 - timer);
		text = FText::FromString(*sTimer);
	}
	else {
		timer = 0;
		text = FText::FromString("Start");
	}

	if (textRender != nullptr) {
		textRender->SetText(text); //Update visual countdown
	}

	if (timer > 500) { //If timer is over 500
		SetActorHiddenInGame(true); //Hide start square
		SetActorLocation(FVector(GetActorLocation().X, -1, GetActorLocation().Z)); //Move Player to SpawnPoint
		return true;
	}
	else {
		return false;
	}
}

//void AcppStartSquare::SpawnEnemies() {
//	//Get all Enemy Spawners
//	TArray<AActor*> playerStarts;
//	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerStarts);
//}