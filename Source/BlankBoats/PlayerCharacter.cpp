// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Controller.h"
#include "Math/Vector.h"
#include "GameFramework/Actor.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//movement setup
	//PlayerMovement = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("PlayerMovement"));
	PlayerMovement = ACharacter::GetCharacterMovement();
	
	//spring arm setup
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	//camera set up
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	//Cannonball
	Cannonball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cannonball"));

	//set values for variables
	turnRate = 45.0f;
	lookRate = 45.0f;
	dashForce = 5000.0f;
	walkSpeed = 600.0f;
	carryingSpeed = 100.0f;
	hasCannonball = false;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

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

void APlayerCharacter::Dash()
{
	FVector forward = GetActorForwardVector();
	forward.Normalize(0.0001);
	PlayerMovement->Velocity = (PlayerMovement->Velocity + forward) * dashForce;
}

void APlayerCharacter::Interact()
{

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hasCannonball)
		PlayerMovement->MaxWalkSpeed = carryingSpeed;
	else
		PlayerMovement->MaxWalkSpeed = walkSpeed;

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
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &APlayerCharacter::Dash);
	//PlayerInputComponent->BindAction("Dash", IE_Released, this, &APlayerCharacter::Dash);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
	//PlayerInputComponent->BindAction("Interact", IE_Released, this, &APlayerCharacter::Interact);
}

