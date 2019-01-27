

#include "ProjectileWeaponComponent.h"
#include "WeaponProjectile.h"

void UProjectileWeaponComponent::Shoot(FVector Location, FQuat Direction)
{
    APawn* Owner = Cast<APawn>(GetOwner());
    FActorSpawnParameters param = FActorSpawnParameters();
    param.Instigator = Owner;
    param.Owner = Owner;

    UWorld* const World = GetWorld();
    if (World != NULL)
    {
        FTransform SpawnTransform = FTransform(Direction);
        SpawnTransform.SetLocation(Location);
        World->SpawnActor(ProjectileClass, &SpawnTransform, param);
    }
}

float UProjectileWeaponComponent::GetWeaponFiringRange() const
{
    return 1000.f;
}
