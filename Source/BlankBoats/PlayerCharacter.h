// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UCharacterMovementComponent;

UCLASS()
class BLANKBOATS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	//character movement reference
	UCharacterMovementComponent* PlayerMovement;

	//components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Props")
	UStaticMeshComponent* Cannonball;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//functions
	void MoveForward(float value);
	void MoveRight(float value);
	void TurnAtRate(float value);
	void LookAtRate(float value);
	void Dash();
	void Interact();

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	float turnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	float lookRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	float dashForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	float walkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	float carryingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vars")
	bool hasCannonball;
};
