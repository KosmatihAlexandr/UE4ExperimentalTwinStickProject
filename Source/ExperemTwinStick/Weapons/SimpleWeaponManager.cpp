

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
    if (Weapon != nullptr)
    {
        return Weapon->GetAmountOfAmmo();
    }
    return 0;
}

EWeaponType USimpleWeaponManager::GetWeaponType() const
{
    if (Weapon != nullptr)
    {
        return Weapon->GetWeaponType();
    }
    return EWeaponType::None;
}

float USimpleWeaponManager::GetWeaponFiringRange() const
{
    if (Weapon != nullptr)
    {
        return Weapon->GetWeaponFiringRange();
    }
    return 0.0f;
}

void USimpleWeaponManager::TakeWeapon(TSubclassOf<UBaseWeaponComponent> WeaponClass)
{
    if (Weapon != nullptr)
    {
        Weapon->UnregisterComponent();
        Weapon->DestroyComponent();
        Weapon->SetActive(false);
    }

    UBaseWeaponComponent* NWeapon = NewObject<UBaseWeaponComponent>(this, WeaponClass);
    if (NWeapon == nullptr)
    {
        return;
    }

    NWeapon->RegisterComponent();
    NWeapon->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
    
    Weapon = NWeapon;

    Weapon->OnNeedAmmo.AddDynamic(this, &USimpleWeaponManager::NeedReload);
}

void USimpleWeaponManager::NeedReload()
{
    Reaload();
}
