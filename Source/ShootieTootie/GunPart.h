// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunPart.generated.h"

UCLASS()
class SHOOTIETOOTIE_API AGunPart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunPart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Properties

	// Static model for nonanimated parts
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  UStaticMeshComponent *PartMesh;
  // Skeletal model for animated parts
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USkeletalMeshComponent *PartMeshSkeletal;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  USceneComponent *VisualScene;
	// Name of the part in the table of gun parts
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GunMods")
  FName PartName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
