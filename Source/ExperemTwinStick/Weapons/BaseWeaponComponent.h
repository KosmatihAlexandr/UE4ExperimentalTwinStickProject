#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "BaseWeaponComponent.generated.h"

UENUM(BlueprintType)
enum EWeaponType
{
    Pistol     UMETA(DisplayName = "Pistol"),
    Rifle      UMETA(DisplayName = "Rifle"),
    None   UMETA(DisplayName = "None")
};

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
    void AbortRealoading();

    UFUNCTION(Category = "Ammo", BlueprintCallable)
    uint8 GetAmmo() const;

protected:

    virtual void BeginPlay() override;

    UBaseWeaponComponent();

    UPROPERTY(Category = "Animation", BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<EWeaponType> AnimType;

    /* Weapon shooting animation */
    UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadWrite)
    class UAnimationAsset* FireAnimation;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float FireRate;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float ReloadTime;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    uint8 AmountOfAmmo;

    virtual void Shoot(FVector Location, FQuat Direction);

private:
    uint8 bCanFire : 1;//TODO delete?
    uint8 bIsShooting : 1;

    uint8 Ammo;

    FTimerHandle TimerHandle_ShotTimerExpired;
    FTimerHandle TimerHandle_ReloadTimerExpired;

    void PrepareShooting();

    void ShotTimerExpired();
    void ReloadTimerExpired();
};
