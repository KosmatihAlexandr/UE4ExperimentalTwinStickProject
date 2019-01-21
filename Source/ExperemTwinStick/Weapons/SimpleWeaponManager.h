

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponManager.h"
#include "SimpleWeaponManager.generated.h"

class UBaseWeaponComponent;

/**
 * 
 */
UCLASS( ClassGroup = (WeapoManager), meta = (BlueprintSpawnableComponent) )
class EXPEREMTWINSTICK_API USimpleWeaponManager : public UWeaponManager
{
	GENERATED_BODY()
	
public:

    virtual bool CanFire() const override;

    virtual void StartShooting() override;

    virtual void StopShooting() override;

    virtual void Reaload() override;

    virtual bool IsRealoading() const override;

    virtual void AbortRealoading() override;

    virtual uint8 GetAmmo() const override;

    UFUNCTION(Category = "Wepon", BlueprintCallable)
    void TakeWeapon(TSubclassOf<UBaseWeaponComponent> WeaponClass);

protected:
    UBaseWeaponComponent* Weapon;
};
