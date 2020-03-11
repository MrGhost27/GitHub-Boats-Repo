// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BLANKBOATS_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

protected:
	float startTimer = 0.0f;
	bool isStartTimerActive;

	// Game Mode keeping track of game variables.
	int playerHealth;
	int enemyHealth;
	// If this approach is good - Do we continue with other variables?
	// For example - Cannon Ready? - This seems like it should be handled by a Cannon actor.  Design question, is there more than 1 cannon?
	// Mission Time remaining? - 
	
	bool isLobby;
	AActor* CannonActor;

public:
	
	void StartNewGame();

	void BeginStartTimer() { isStartTimerActive = true; }
	void EndStartTimer() { isStartTimerActive = false; }
	float ReturnStartTimer() { return startTimer; } // Make Tick part of another Actor Class - A Starter Square? Why is this timer the Game Mode's responsibility?
	void LobbyTick();

	// Gameplay functions shouldn't be on Game Mode.
	void FriendlyCannonFire(); // Friendly Cannon Actor
	void EnemyCannonFire();	   // Enemy Cannon Actor
	
	// EndGame Circumstances reached.
	void GameWon();	// Play Win sounds
	void GameLost(); // Play Boo sounds

	void GameIsOver(); // Both conditions will need to do the same things. Reset the game to the lobby.
};
