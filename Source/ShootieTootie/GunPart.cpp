// Fill out your copyright notice in the Description page of Project Settings.


#include "GunPart.h"

// Sets default values
AGunPart::AGunPart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
        VisualScene =
            CreateDefaultSubobject<class USceneComponent>(TEXT("VisualScene"));
  PartMesh = CreateDefaultSubobject<class UStaticMeshComponent>(
      TEXT("PartMesh"));
  RootComponent = VisualScene;
  PartMesh->SetupAttachment(VisualScene);
  PartMeshSkeletal = CreateDefaultSubobject<class USkeletalMeshComponent>(
     TEXT("PartMeshSkeletal"));
  PartMeshSkeletal->SetupAttachment(VisualScene);
}

// Called when the game starts or when spawned
void AGunPart::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

