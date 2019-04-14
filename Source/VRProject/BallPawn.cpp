// Fill out your copyright notice in the Description page of Project Settings.

#include "BallPawn.h"
#include "Classes/Components/InputComponent.h"
#include "Classes/GameFramework/FloatingPawnMovement.h"
#include "Classes/Camera/CameraComponent.h"

// Sets default values
ABallPawn::ABallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	Camera->SetupAttachment(StaticMesh);

	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ABallPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABallPawn::MoveForward(float Amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);
}

void ABallPawn::MoveRight(float Amount)
{
	FloatingPawnMovement->AddInputVector(GetActorRightVector() * Amount);
}

// Called every frame
void ABallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABallPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABallPawn::MoveRight);

}

