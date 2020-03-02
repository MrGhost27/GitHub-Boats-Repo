// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovePawn.h"
#include "Classes/Components/InputComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/Camera/CameraComponent.h"

// Sets default values
ACustomMovePawn::ACustomMovePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Players Mesh");
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	Camera->SetupAttachment(StaticMesh);

	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ACustomMovePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACustomMovePawn::MoveForward(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * amount);
}

void ACustomMovePawn::MoveRight(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorRightVector() * amount);
}

// Called every frame
void ACustomMovePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomMovePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardMoveAxis", this, &ACustomMovePawn::MoveForward);
	PlayerInputComponent->BindAxis("RightMoveAxis", this, &ACustomMovePawn::MoveRight);
}

