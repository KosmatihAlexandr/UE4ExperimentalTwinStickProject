

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
