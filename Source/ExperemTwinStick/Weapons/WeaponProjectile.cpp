

#include "WeaponProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AWeaponProjectile::AWeaponProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
    
}

void AWeaponProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

