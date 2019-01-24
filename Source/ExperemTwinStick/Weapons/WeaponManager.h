

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WeaponEnums.h"
#include "WeaponManager.generated.h"


UCLASS( ClassGroup=(WeapoManager), Abstract)
class EXPEREMTWINSTICK_API UWeaponManager : public USceneComponent
{
	GENERATED_BODY()

public:	

    UFUNCTION(Category = "Shooting", BlueprintCallable)
    virtual bool CanFire() const;

    UFUNCTION(Category = "Shooting", BlueprintCallable)
    virtual void StartShooting();

    UFUNCTION(Category = "Shooting", BlueprintCallable)
    virtual void StopShooting();

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    virtual void Reaload();

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    virtual bool IsRealoading() const;

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    virtual void AbortRealoading();

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    virtual uint8 GetAmmo() const;

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    virtual uint8 GetAmountOfAmmo() const;

    UFUNCTION(Category = "WeapoType", BlueprintCallable)
    virtual EWeaponType GetWeaponType() const;

protected:
	
};
