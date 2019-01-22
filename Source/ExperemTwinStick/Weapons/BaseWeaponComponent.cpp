#include "BaseWeaponComponent.h"
#include "TimerManager.h"
#include "Animation/AnimInstance.h"

UBaseWeaponComponent::UBaseWeaponComponent()
{
    AnimationMode = EAnimationMode::AnimationCustomMode;
}

void UBaseWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
    bCanFire = true;
}

bool UBaseWeaponComponent::CanFire() const
{
    return bCanFire;
}

void UBaseWeaponComponent::StartShooting()
{
    bIsShooting = true;
    PrepareShooting();
}

void UBaseWeaponComponent::StopShooting()
{
    bIsShooting = false;
}

bool UBaseWeaponComponent::IsRealoading() const
{
    return false;
}

uint8 UBaseWeaponComponent::RealoadAmmo(uint8 amount)
{
    if (ReloadAnimation != nullptr)
    {
        PlayAnimation(ReloadAnimation, false);
    }
    GetWorld()->GetTimerManager().SetTimer(TimerHandle_ReloadTimerExpired, this, &UBaseWeaponComponent::ReloadTimerExpired, ReloadTime);
    return amount - AmountOfAmmo + Ammo;
}

void UBaseWeaponComponent::AbortRealoading()
{

}

uint8 UBaseWeaponComponent::GetAmmo() const
{
    return Ammo;
}

uint8 UBaseWeaponComponent::GetAmountOfAmmo() const
{
    return AmountOfAmmo;
}

bool UBaseWeaponComponent::IsAmmoLeft() const
{
    return Ammo > 0;
}

void UBaseWeaponComponent::PrepareShooting()
{
    if (bIsShooting && bCanFire)
    {
        if (IsAmmoLeft())
        {

            bCanFire = false;

            if (FireAnimation != nullptr)
            {
                PlayAnimation(FireAnimation, false);
            }

            Ammo -= 1;

            FVector MuzzleLocation;
            FQuat MuzzleRotation;
            GetSocketWorldLocationAndRotation(TEXT("MuzzleFlash"), MuzzleLocation, MuzzleRotation);

            Shoot(MuzzleLocation, MuzzleRotation);

            GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UBaseWeaponComponent::ShotTimerExpired, FireRate);
        }
    }
}

void UBaseWeaponComponent::ShotTimerExpired()
{
    bCanFire = true;
    PrepareShooting();
}

void UBaseWeaponComponent::ReloadTimerExpired()
{
    Ammo = AmountOfAmmo;
}

void UBaseWeaponComponent::Shoot(FVector Location, FQuat Direction)
{

}
