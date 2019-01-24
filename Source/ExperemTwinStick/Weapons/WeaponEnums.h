

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum EWeaponType
{
    Pistol     UMETA(DisplayName = "Pistol"),
    Rifle      UMETA(DisplayName = "Rifle"),
    None   UMETA(DisplayName = "None")
};