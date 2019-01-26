

#include "WeaponManager.h"

bool UWeaponManager::CanFire() const
{
    return false;
}

void UWeaponManager::StartShooting()
{
}

void UWeaponManager::StopShooting()
{
}

void UWeaponManager::Reaload()
{
}

bool UWeaponManager::IsRealoading() const
{
    return false;
}

void UWeaponManager::AbortRealoading()
{
}

uint8 UWeaponManager::GetAmmo() const
{
    return uint8();
}

uint8 UWeaponManager::GetAmountOfAmmo() const
{
    return uint8();
}

float UWeaponManager::GetWeaponFiringRange() const
{
    return 0.0f;
}

EWeaponType UWeaponManager::GetWeaponType() const
{
    return EWeaponType::None;
}
