#pragma once

#include "CoreMinimal.h"

// Enumerations

UENUM(BlueprintType)
// All the cartridges
enum class EAmmoType : uint8 {
  PS7N6 UMETA(DisplayName = "7N6 5.45x39")
};

UENUM(BlueprintType)
// Types of firearms by their bolt position
enum class EBoltType : uint8 {
  open_bolt UMETA(DisplayName =
                       "Open bolt"), // Bolt moves forward than backwards
  closed_bolt UMETA(DisplayName =
                         "Closed bolt") // Bolt moves backwards than forward
};

UENUM(BlueprintType)
// Types of firearms by their cycling method
enum class ECyclingType : uint8 {
  cannot_fire UMETA(DisplayName =
                         "Can't fire"), // Used for non functional guns or the
                                        // ones that are set on safety
  single_shot UMETA(DisplayName =
                         "Single shot"), // Manual cycle with no magazine
  single_action UMETA(DisplaName =
                           "Single action"), // Needs to be cycled manually
  semi_auto UMETA(
      DisplayName =
          "Semi-automatic"), // Loading part of cycle is automatic, firing isn't
  burst_fire UMETA(DisplayName =
                        "Burst fire"), // Fully cycles itself, but fires a
                                       // limited number of shots
  full_auto UMETA(DisplayName =
                       "Fully-automatic") // Fully automatic firing cycle
};

UENUM(BlueprintType)
// States that affect character's upper body animations
enum class EHumanoidArmStates : uint8 {
  null UMETA(DisplayName = "Default state"), // default state
  interacting UMETA(
      DisplayName = "Interacting"), // character interacting with interactables
  attacking UMETA(DisplayName = "Attacking"), // character uses weapon
  picking UMETA(DisplayName = "Picking"),     // character picks an item
  throwing UMETA(DisplayName = "Throwing")
};