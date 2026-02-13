// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Magazine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "ProjectEnums.h"
#include "GunPart.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTIETOOTIE_API AGun : public AWeapon
{
	GENERATED_BODY()
	protected:
		// Properties

    // Without these parts the gun won't fire
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun mechanics")
    TArray<FName> EssentialMods;
		// Magazine currently loaded into the gun
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
    AMagazine *Magazine;
    // Current firing mode of the gun
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun mechanics")
    ECyclingType Mode;
		// All modes of fire the gun can switch between
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun mechanics")
    TArray<ECyclingType> Modes;
    // All the mods installed on the weapon
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun mechanics")
    TArray<AGunPart*> Mods;
};
