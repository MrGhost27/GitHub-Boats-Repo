// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableBase.h"
#include "Engine.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//
//void AInteractableBase::OnInteract(AActor * Caller)
//{
//	/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("INTERACTED"));*/
//}
//
void AInteractableBase::OnInteract_Implementation(AActor* Caller)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("INTERACTED"));
	Destroy();
}

void AInteractableBase::OnEnter_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("ENTERED"));
}

void AInteractableBase::OnExit_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("EXITED"));
}

