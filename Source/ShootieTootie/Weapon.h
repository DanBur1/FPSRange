// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectEnums.h"
#include "Weapon.generated.h"

UCLASS()
class SHOOTIETOOTIE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Default Unreal events

	// Sets default values for this actor's properties
	AWeapon();
  // Called every frame
  virtual void Tick(float DeltaTime) override;

	// Methods

	// Sets the weapon in the attacking state
  void startAttacking();

protected:
	// Default unreal events
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Properties

	// Current animation the character is supposed to have
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animations")
	EHumanoidArmStates AnimState;
	// Time it takes to reset the weapon after attacking
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun mechanics")
  float cooldown;
	// Boolean that returns true if the weapon still haven't recovered from attacking
  bool is_cooling_down;
  // Current firing mode of the gun
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun mechanics")
  ECyclingType Mode;
  // All modes of fire the gun can switch between
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun mechanics")
  TArray<ECyclingType> Modes;
	// Timer that handles weapon cooldown
  UPROPERTY()
  FTimerHandle AttackCooldownTimer;
	// Model
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USkeletalMeshComponent *WeaponMesh;

	// Methods

	// Sets the weapon back to non attacking state
  void finishAttacking();
};
