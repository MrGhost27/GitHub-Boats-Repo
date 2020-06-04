// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "cppStartSquare.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Math/Vector.h"
#include "GameFramework/Actor.h"
#include "InteractInterfaceBase.h"
#include "Components/CapsuleComponent.h"
#include "Engine.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	//Set up References
	CapsuleRef = ACharacter::GetCapsuleComponent(); //Capsule
	PlayerMovement = ACharacter::GetCharacterMovement(); //Player Movement Controller

	//Set up Rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	PlayerMovement->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	PlayerMovement->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate

 	// Call Tick() Every Frame.
	PrimaryActorTick.bCanEverTick = true;
	
	//Set Variables
	turnRate = 45.0f;
	lookRate = 45.0f;
	dashForce = 5000.0f;
	walkSpeed = 3000.0f;
	carryingSpeed = 500.0f;
	hasCannonball = false;
	canInteract = false;
	spawned = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorHiddenInGame(true); //Make Player Invisible
}

//------------ Functions ----------------

//--------- Axis Functions --------------

void APlayerCharacter::MoveForward(float value)
{
	if ((Controller) && (value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if ((Controller) && (value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::TurnAtRate(float value)
{
	AddControllerYawInput(value * turnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookAtRate(float value)
{
	AddControllerPitchInput(value * lookRate * GetWorld()->GetDeltaSeconds());
}

//------------ Action Functions ---------------

void APlayerCharacter::SpawnPressed()
{
	if (!spawned) { //Check PLayer Isn't Already Spawned
		//Format PlayerNo
		FString sPlayerNo = FString::FromInt(playerNo);
		FName nPlayerNo = FName(*sPlayerNo);

		//Get all playerStarts
		TArray<AActor*> playerStarts;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerStarts);

		for (AActor* playerStart : playerStarts) { //Check all PlayerStarts
			if (playerStart->ActorHasTag(nPlayerNo)) { //Find PlayerStart Matching Current Player
				SetActorLocation(playerStart->GetActorLocation()); //Move Player to SpawnPoint
				SetActorHiddenInGame(false); //Make Player Visible
				spawned = true; //Set Player as Spawned
			}
		}
	}
	else {
		//Get all playerStarts
		TArray<AActor*> playerStarts;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerStarts);

		for (AActor* playerStart : playerStarts) { //Check all PlayerStarts
			if (playerStart->ActorHasTag(FName("preSpawn"))) { //Find PlayerStart Matching Current Player
				SetActorLocation(playerStart->GetActorLocation()); //Move Player to SpawnPoint
				SetActorHiddenInGame(true); //Make Player Visible
				spawned = false; //Set Player as Spawned
			}
		}
	}
}

void APlayerCharacter::Dash()
{
	FVector forward = GetActorForwardVector();
	forward.Normalize(0.0001);
	PlayerMovement->Velocity = (PlayerMovement->Velocity + forward) * dashForce;
}

void APlayerCharacter::InteractPressed()
{
	/*if (canInteract)
	{
		AActor* OtherActor;
		IInteractInterfaceBase* Interface = Cast<IInteractInterfaceBase>(OtherActor);

		if (Interface)
		{
			Interface->Execute_OnInteract(OtherActor,this);
		}
	}*/
	//This needs to call whatever function, not be a function
	if(canInteract)
		InteractWithStation();
}
//
void APlayerCharacter::InteractWithStation_Implementation()
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("INTERACTED"));
}

//void APlayerCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	canInteract = true;
//}
//
//void APlayerCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
//{
//	canInteract = false;
//}

bool APlayerCharacter::GetHasCannonball()
{
	return hasCannonball;
}

float APlayerCharacter::GetTurnRate()
{
	return turnRate;
}

float APlayerCharacter::GetLookRate()
{
	return lookRate;
}

float APlayerCharacter::GetDashForce()
{
	return dashForce;
}

float APlayerCharacter::GetWalkSpeed()
{
	return walkSpeed;
}

float APlayerCharacter::GetCarryingSpeed()
{
	return carryingSpeed;
}

bool APlayerCharacter::GetCanInteract()
{
	return canInteract;
}

void APlayerCharacter::SetHasCannonball()
{
	hasCannonball = !hasCannonball;
}

void APlayerCharacter::SetTurnRate(float v)
{
	turnRate = v;
}

void APlayerCharacter::SetLookRate(float v)
{
	lookRate = v;
}

void APlayerCharacter::SetDashForce(float v)
{
	dashForce = v;
}

void APlayerCharacter::SetWalkSpeed(float v)
{
	walkSpeed = v;
}

void APlayerCharacter::SetCarryingSpeed(float v)
{
	carryingSpeed = v;
}

void APlayerCharacter::SetCanInteract()
{
	canInteract = !canInteract;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hasCannonball)
	{
		//Cannonball->SetVisibility(true);
		PlayerMovement->MaxWalkSpeed = carryingSpeed;
	}
	else
	{
		//Cannonball->SetVisibility(false);
		PlayerMovement->MaxWalkSpeed = walkSpeed;
	}

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//axis bindings
	PlayerInputComponent->BindAxis("ForwardMoveAxis",this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("RightMoveAxis",this,&APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look",this, &APawn::AddControllerPitchInput);
	//Action bindings
	PlayerInputComponent->BindAction("Spawn", IE_Pressed, this, &APlayerCharacter::SpawnPressed);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &APlayerCharacter::Dash);
	//PlayerInputComponent->BindAction("Dash", IE_Released, this, &APlayerCharacter::Dash);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &APlayerCharacter::InteractPressed);
	//PlayerInputComponent->BindAction("Interact", IE_Released, this, &APlayerCharacter::Interact);
}

