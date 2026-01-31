// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter.h"

// Sets default values
AShooter::AShooter() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = false;

  // Setting up the components
  ShooterMesh =
      CreateDefaultSubobject<class USkeletalMeshComponent>(TEXT("ShooterMesh"));
  Camera = CreateDefaultSubobject<class UCameraComponent>(TEXT("Camera"));
  Capsule = CreateDefaultSubobject<class UCapsuleComponent>(TEXT("Capsule"));
  Movement =
      CreateDefaultSubobject<class UCharacterMovementComponent>("Movement");

  // Capsule size setup
  Capsule->SetCapsuleHalfHeight(90.0f);
  Capsule->SetCapsuleRadius(40.0f);

  // Hierarchy
  RootComponent = Capsule;
  ShooterMesh->SetupAttachment(RootComponent);
  Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

