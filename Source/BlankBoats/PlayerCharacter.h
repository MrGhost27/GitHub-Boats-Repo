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
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void MoveForward(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void MoveRight(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void TurnAtRate(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void LookAtRate(float value);
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void Dash();
	UFUNCTION(BlueprintCallable, Category = "PlayerFunctions")
	void Interact();

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
	bool hasCannonball;
};
