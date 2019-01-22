

#include "TraceWeaponComponent.h"
#include "Kismet/GameplayStatics.h"

void UTraceWeaponComponent::Shoot(FVector Location, FQuat Direction)
{
    UWorld* World = GetWorld();
    if (World != nullptr)
    {
        FHitResult Hit;
        FVector EndLocation = Location + Direction.Vector() * Distance;

        const FName TraceTag("MyTraceTag");

        World->DebugDrawTraceTag = TraceTag;

        FCollisionQueryParams CollisionParams = FCollisionQueryParams::DefaultQueryParam;
        CollisionParams.TraceTag = TraceTag;
        
        if (World->LineTraceSingleByChannel(Hit, Location, EndLocation, ECollisionChannel::ECC_Camera, CollisionParams))
        {
            AActor* Owner = GetOwner();
            UGameplayStatics::ApplyPointDamage(Hit.GetActor(), Damage, Hit.Normal, Hit, Owner->GetInstigatorController(), Owner, DamageType);
        }
    }
}