// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cppStartSquare.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UCapsuleComponent;
class UCharacterMovementComponent;

UCLASS()
class BLANKBOATS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	//References
	UCharacterMovementComponent* PlayerMovement;
	UCapsuleComponent* CapsuleRef;
	UStaticMeshComponent* MeshRef;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//General Functions


	//Axis Functions
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void MoveForward(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void MoveRight(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void TurnAtRate(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void LookAtRate(float value);

	//Action Functions
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SpawnPressed();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void Dash();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void InteractPressed();
	UFUNCTION(BlueprintNativeEvent)
	void InteractWithStation();
	void InteractWithStation_Implementation();

	//Event Functions

	//getters
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	bool GetHasCannonball();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	float GetTurnRate();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	float GetLookRate();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	float GetDashForce();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	float GetWalkSpeed();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	float GetCarryingSpeed();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	bool GetCanInteract();

	//setters
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetHasCannonball();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetTurnRate(float v);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetLookRate(float v);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetDashForce(float v);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetWalkSpeed(float v); 
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetCarryingSpeed(float v);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void SetCanInteract();

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float turnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float lookRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float dashForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float walkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float carryingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float objectLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	float pickUpDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	int32 playerNo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	bool hasCannonball;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	bool canInteract;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	bool spawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	bool physicsHandleActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	bool isHeld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	TArray<AActor*> playerStarts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerVariables")
	AcppStartSquare* startSquare;
};