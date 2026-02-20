// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Weapon.h"
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

  // Methods

  // Takes character weapon and calls its startAttacking function
  void useWeapon();

protected:
  // Unreal default events
  
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // Properties

  // First person camera
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
  UCameraComponent *Camera;
  // Collision
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
  UCapsuleComponent *Capsule;
  // Character movement
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  UCharacterMovementComponent *Movement;
  // Character model
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USkeletalMeshComponent *ShooterMesh;
  // Weapon character currently has
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
  AWeapon *Weapon;
  // Class of the weapon character uses. Can be used to set starter weapon
  UPROPERTY(EditAnywhere, Category = "Weapons")
  TSubclassOf<AWeapon> WeaponClass;
};
