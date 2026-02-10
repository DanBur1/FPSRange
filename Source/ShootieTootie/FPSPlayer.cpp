// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayer.h"

void AFPSPlayer::OnPossess(APawn *InPawn) {
  Super::OnPossess(InPawn);

  if (InPawn) {
    // Get possessed pawn
    PlayerCharacter = Cast<AShooter>(InPawn);
    // Adds IMC_FPS
    if (ULocalPlayer *LocalPlayer = GetLocalPlayer()) {
      if (UEnhancedInputLocalPlayerSubsystem *Subsystem =
              ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
                  LocalPlayer)) {
        Subsystem->AddMappingContext(InputMappingContext, 0);
      }
    }
  }
}

void AFPSPlayer::SetupInputComponent(){
  Super::SetupInputComponent();

  // Bind functions to actions
  if (UEnhancedInputComponent *EnhancedInputComponent =
          Cast<UEnhancedInputComponent>(InputComponent)) {
    // Turning camera up and down
    if (LookUpAction) {
      EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered,
                                         this, &AFPSPlayer::onLook);
    }
    // Opening the menu
    if (MenuAction) {
      EnhancedInputComponent->BindAction(MenuAction, ETriggerEvent::Started,
                                         this, &AFPSPlayer::onMenu);
    }
    // Turning sideways
    if (TurnAction) {
      EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered,
                                         this, &AFPSPlayer::onTurn);
    }
  }
}

void AFPSPlayer::onLook(const FInputActionValue &Value){
  float pitch_value = -Value.Get<float>();
  AddPitchInput(pitch_value * mouse_sensitivity);
}

void AFPSPlayer::onMenu(){
  if (MenuWidget){
    if (MenuWidget->IsVisible()) {
      SetInputMode(FInputModeGameOnly());
      bShowMouseCursor = false;
      MenuWidget->SetVisibility(ESlateVisibility::Hidden);
    } else {
      SetInputMode(FInputModeUIOnly());
      bShowMouseCursor = true;
    }
      MenuWidget->SetVisibility(ESlateVisibility::Visible);
  } else if (MenuWidgetClass){
    MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
    MenuWidget->AddToViewport();
    MenuWidget->SetVisibility(ESlateVisibility::Visible);
    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
  }
}

void AFPSPlayer::onTurn(const FInputActionValue &Value) {
  float yaw_value = Value.Get<float>();
  AddYawInput(yaw_value * mouse_sensitivity);
}