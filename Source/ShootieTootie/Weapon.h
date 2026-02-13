// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected:
	// Default unreal events
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Properties

	// Model
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USkeletalMeshComponent *WeaponMesh;

};
