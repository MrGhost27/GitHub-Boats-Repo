// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterfaceBase.h"
#include "PlayerCharacter.h"
#include "InteractableBase.generated.h"

UCLASS()
class BLANKBOATS_API AInteractableBase : public AActor, public IInteractInterfaceBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StationVariables")
	bool inStation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract(AActor* Caller); //APlayerCharacter* Player
	virtual void OnInteract_Implementation(AActor* Caller); //APlayerCharacter* Player
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnEnter();
	virtual void OnEnter_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnExit();
	virtual void OnExit_Implementation();
};
