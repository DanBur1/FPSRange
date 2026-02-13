// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <EnhancedInputSubsystems.h>
#include <InputMappingContext.h>
#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Shooter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "FPSPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTIETOOTIE_API AFPSPlayer : public APlayerController
{
	GENERATED_BODY()
public:
	// Default unreal evets

	// Called when controller is assigned a player
  virtual void OnPossess(APawn *InPawn) override;

protected:
	// Defailt unreal events

	// Setting up inputs and their actions
	virtual void SetupInputComponent() override;

	// Properties

	// Camera settings
  // Sensetivity of camera reacting to mouse movement
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
  float mouse_sensitivity = 1.f;
	// Controller up and down rotation lower limit
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
  float min_pitch = -80.f;
	// Controller up and down rotation upper limit
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
  float max_pitch = 80.f;
	// Character
	// Player class cast to shooter
  AShooter *PlayerCharacter; 
	// Input Actions
	// IA_LookUp
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
  class UInputAction *LookUpAction;
	// IA_Menu
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
  UInputAction *MenuAction;
	// IA_Turn
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
  class UInputAction *TurnAction;
	// Other
  // Current mapping context
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
  UInputMappingContext *InputMappingContext;
  // Widget of the menu
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
  TSubclassOf<UUserWidget> MenuWidgetClass;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
  UUserWidget *MenuWidget;

	// Methods

  // Reactions to action events
	// Reaction to IA_LookUp
  void onLook(const FInputActionValue &Value);
  // Reaction to IA_Menu
  void onMenu();
	// Reaction to IA_Turn
  void onTurn(const FInputActionValue &Value);
  // Others
  // Opens and closes WBP_Menu widget
  void toggleMenu(bool is_open);
};
