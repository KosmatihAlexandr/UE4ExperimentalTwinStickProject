#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "WeaponEnums.h"
#include "BaseWeaponComponent.generated.h"

/**
 * 
 */
UCLASS()
class EXPEREMTWINSTICK_API UBaseWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
    UFUNCTION(Category = "Shooting", BlueprintCallable)
    bool CanFire() const;

    UFUNCTION(Category = "Shooting", BlueprintCallable)
    void StartShooting();

    UFUNCTION(Category = "Shooting", BlueprintCallable)
    void StopShooting();

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    uint8 RealoadAmmo(uint8 amount);

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    bool IsRealoading() const;

    UFUNCTION(Category = "Reloading", BlueprintCallable)
    uint8 AbortRealoading();

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    uint8 GetAmmo() const;

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    uint8 GetAmountOfAmmo() const;

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    bool IsAmmoLeft() const;

    UFUNCTION(Category = "WeapoType", BlueprintCallable)
    EWeaponType GetWeaponType() const;

protected:

    virtual void BeginPlay() override;

    UBaseWeaponComponent();

    UPROPERTY(Category = "Animation", BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<EWeaponType> WeaponType;

    /* Weapon shooting animation */
    UPROPERTY(Category = "Animation", EditAnywhere, BlueprintReadWrite)
    class UAnimationAsset* FireAnimation;

    UPROPERTY(Category = "Animation", EditAnywhere, BlueprintReadWrite)
    class UAnimationAsset* ReloadAnimation;

    UPROPERTY(Category = "Animation", EditAnywhere, BlueprintReadWrite)
    UAnimMontage* FireAnimationMontage;

    UPROPERTY(Category = "Animation", EditAnywhere, BlueprintReadWrite)
    UAnimMontage* ReloadAnimationMontage;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float FireRate;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float ReloadTime;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    uint8 AmountOfAmmo;

    virtual void Shoot(FVector Location, FQuat Direction);

private:
    uint8 bIsShooting : 1;

    uint8 Ammo;

    FTimerHandle TimerHandle_ShotTimerExpired;
    FTimerHandle TimerHandle_ReloadTimerExpired;

    void PrepareShooting();

    void ShotTimerExpired();
    void ReloadTimerExpired();
};
