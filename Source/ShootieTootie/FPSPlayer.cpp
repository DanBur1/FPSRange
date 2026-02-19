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
    // Shooting tooting
    if (ShootAction) {
      EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started,
                                         this, &AFPSPlayer::onShoot);
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
      toggleMenu(true);
    } else {
      toggleMenu(false);
    }
  } else if (MenuWidgetClass){
    MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
    MenuWidget->AddToViewport();
    toggleMenu(false);
  }
}

void AFPSPlayer::onShoot(){
  if (!PlayerCharacter)
    return;
  PlayerCharacter->useWeapon();
}

void AFPSPlayer::onTurn(const FInputActionValue &Value) {
  float yaw_value = Value.Get<float>();
  AddYawInput(yaw_value * mouse_sensitivity);
}

void AFPSPlayer::toggleMenu(bool is_open){
  UE_LOG(LogTemp, Warning, TEXT("Is open - %d"), is_open);
  if (is_open) {
    UGameplayStatics::SetGamePaused(GetWorld(), false);
    SetInputMode(FInputModeGameOnly());
    bShowMouseCursor = false;
    MenuWidget->SetVisibility(ESlateVisibility::Hidden);
  } else {
    //UGameplayStatics::SetGamePaused(GetWorld(), true);
    MenuWidget->SetVisibility(ESlateVisibility::Visible);
    SetInputMode(FInputModeGameAndUI());
    bShowMouseCursor = true;
  }
}