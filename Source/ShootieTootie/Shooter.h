// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Shooter.generated.h"

UCLASS()
class SHOOTIETOOTIE_API AShooter : public APawn
{
	GENERATED_BODY()

public:
  // Unreal default events
  
	// Sets default values for this pawn's properties
	AShooter();
  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
  // Called every frame
  virtual void Tick(float DeltaTime) override;

protected:
  // Unreal default events
  
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // Properties

  // Character model
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
  USkeletalMeshComponent *ShooterMesh;
};
