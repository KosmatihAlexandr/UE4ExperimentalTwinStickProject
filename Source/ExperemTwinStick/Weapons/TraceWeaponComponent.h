

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeaponComponent.h"
#include "TraceWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class EXPEREMTWINSTICK_API UTraceWeaponComponent : public UBaseWeaponComponent
{
	GENERATED_BODY()
	
protected:
    virtual void Shoot() override;
};
