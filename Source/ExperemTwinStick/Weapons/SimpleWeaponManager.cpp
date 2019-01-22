

#include "SimpleWeaponManager.h"
#include "BaseWeaponComponent.h"

bool USimpleWeaponManager::CanFire() const
{
    if (Weapon != nullptr)
    {
        return Weapon->CanFire();
    }
    return false;
}

void USimpleWeaponManager::StartShooting()
{
    if (Weapon != nullptr)
    {
        Weapon->StartShooting();
    }
}

void USimpleWeaponManager::StopShooting()
{
    if (Weapon != nullptr)
    {
        Weapon->StopShooting();
    }
}

void USimpleWeaponManager::Reaload()
{
    if (Weapon != nullptr)
    {
        Weapon->RealoadAmmo(Weapon->GetAmountOfAmmo());
    }
}

bool USimpleWeaponManager::IsRealoading() const
{
    if (Weapon != nullptr)
    {
        return Weapon->IsRealoading();
    }
    return false;
}

void USimpleWeaponManager::AbortRealoading()
{
    if (Weapon != nullptr)
    {
        Weapon->AbortRealoading();
    }
}

uint8 USimpleWeaponManager::GetAmmo() const
{
    if (Weapon != nullptr)
    {
        return Weapon->GetAmmo();
    }
    return 0;
}

uint8 USimpleWeaponManager::GetAmountOfAmmo() const
{
    return Weapon->GetAmountOfAmmo();
}

void USimpleWeaponManager::TakeWeapon(TSubclassOf<UBaseWeaponComponent> WeaponClass)
{
    Weapon = NewObject<UBaseWeaponComponent>(this, WeaponClass, TEXT("Weapon"));
    if (Weapon == nullptr)
    {
        return;
    }

    Weapon->RegisterComponent();
    Weapon->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
}
