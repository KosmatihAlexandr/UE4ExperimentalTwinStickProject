

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeaponComponent.h"
#include "ProjectileWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class EXPEREMTWINSTICK_API UProjectileWeaponComponent : public UBaseWeaponComponent
{
	GENERATED_BODY()
	
public:
    virtual float GetWeaponFiringRange() const override;

protected:

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<class AWeaponProjectile> ProjectileClass;

    virtual void Shoot(FVector Location, FQuat Direction) override;

};
