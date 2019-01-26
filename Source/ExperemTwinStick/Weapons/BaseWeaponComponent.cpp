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
    Ammo = AmountOfAmmo;
}

bool UBaseWeaponComponent::CanFire() const
{
    return !TimerHandle_ReloadTimerExpired.IsValid() && !TimerHandle_ShotTimerExpired.IsValid();
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
    if (Ammo >= AmountOfAmmo)
    {
        return amount;
    }
    if (TimerHandle_ReloadTimerExpired.IsValid())
    {
        return amount;
    }

    if (ReloadAnimation != nullptr)
    {
        PlayAnimation(ReloadAnimation, false);
    }
    USkeletalMeshComponent* Owner = Cast<USkeletalMeshComponent>(GetAttachParent()->GetAttachParent());

    if (Owner != nullptr && ReloadAnimationMontage != nullptr)
    {
        UAnimInstance* AnimInstance = Owner->GetAnimInstance();
        if (AnimInstance != nullptr)
        {
            AnimInstance->Montage_Play(ReloadAnimationMontage);
        }
    }
    GetWorld()->GetTimerManager().SetTimer(TimerHandle_ReloadTimerExpired, this, &UBaseWeaponComponent::ReloadTimerExpired, ReloadTime);
    return amount - AmountOfAmmo + Ammo;
}

uint8 UBaseWeaponComponent::AbortRealoading()
{
    TimerHandle_ReloadTimerExpired.Invalidate();
    USkeletalMeshComponent* Owner = Cast<USkeletalMeshComponent>(GetAttachParent()->GetAttachParent());

    if (Owner != nullptr && ReloadAnimationMontage != nullptr)
    {
        UAnimInstance* AnimInstance = Owner->GetAnimInstance();
        if (AnimInstance != nullptr)
        {
            AnimInstance->Montage_Stop(0.1f, ReloadAnimationMontage);
        }
    }
    return AmountOfAmmo - Ammo;
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

EWeaponType UBaseWeaponComponent::GetWeaponType() const
{
    return WeaponType;
}

float UBaseWeaponComponent::GetWeaponFiringRange() const
{
    return 0.0f;
}

void UBaseWeaponComponent::PrepareShooting()
{
    if (bIsShooting && CanFire())
    {
        if (IsAmmoLeft())
        {
            if (FireAnimation != nullptr)
            {
                PlayAnimation(FireAnimation, false);
            }

            Ammo -= 1;

            FVector MuzzleLocation;
            FQuat MuzzleRotation;
            GetSocketWorldLocationAndRotation(TEXT("MuzzleFlash"), MuzzleLocation, MuzzleRotation);

            Shoot(MuzzleLocation, MuzzleRotation);

            USkeletalMeshComponent* Owner = Cast<USkeletalMeshComponent>(GetAttachParent()->GetAttachParent());
            
            if (Owner != nullptr && FireAnimationMontage != nullptr)
            {
                UAnimInstance* AnimInstance = Owner->GetAnimInstance();
                if (AnimInstance != nullptr)
                {
                    AnimInstance->Montage_Play(FireAnimationMontage);
                }
            }
            
            GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &UBaseWeaponComponent::ShotTimerExpired, FireRate);
        }
        else
        {
            OnNeedAmmo.Broadcast();
        }
    }
}

void UBaseWeaponComponent::ShotTimerExpired()
{
    TimerHandle_ShotTimerExpired.Invalidate();
    PrepareShooting();
}

void UBaseWeaponComponent::ReloadTimerExpired()
{
    TimerHandle_ReloadTimerExpired.Invalidate();
    Ammo = AmountOfAmmo;
    PrepareShooting();
}

void UBaseWeaponComponent::Shoot(FVector Location, FQuat Direction)
{

}
