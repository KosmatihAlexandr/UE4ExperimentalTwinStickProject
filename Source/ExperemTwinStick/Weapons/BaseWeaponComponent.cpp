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

bool UBaseWeaponComponent::CanFire()
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

bool UBaseWeaponComponent::IsRealoading()
{
    return false;
}

uint8 UBaseWeaponComponent::RealoadAmmo(uint8 amount)
{
    return uint8();
}

void UBaseWeaponComponent::AbortRealoading()
{

}

uint8 UBaseWeaponComponent::GetAmmo()
{
    return Ammo;
}

void UBaseWeaponComponent::PrepareShooting()
{
    if (bIsShooting && bCanFire)
    {
        if (FireAnimation != nullptr)
        {
            PlayAnimation(FireAnimation, false);
        }

        bCanFire = false;

        Ammo -= 1;

        Shoot();

        GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UBaseWeaponComponent::ShotTimerExpired, FireRate);
    }
}

void UBaseWeaponComponent::ShotTimerExpired()
{
    bCanFire = true;
    PrepareShooting();
}

void UBaseWeaponComponent::ReloadTimerExpired()
{

}

void UBaseWeaponComponent::Shoot()
{

}
