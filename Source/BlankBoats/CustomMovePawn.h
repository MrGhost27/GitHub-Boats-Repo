// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CustomMovePawn.generated.h"

UCLASS()
class BLANKBOATS_API ACustomMovePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomMovePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float amount);
	void MoveRight(float amount);
	void Dash();

	class UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Components")
	AActor* OverheadCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
