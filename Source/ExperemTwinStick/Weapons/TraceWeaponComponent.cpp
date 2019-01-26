

#include "TraceWeaponComponent.h"
#include "Kismet/GameplayStatics.h"

void UTraceWeaponComponent::Shoot(FVector Location, FQuat Direction)
{
    UWorld* World = GetWorld();
    if (World != nullptr)
    {
        FHitResult Hit;
        FVector EndLocation;
        FVector DirectionVector;
        
        for (uint8 i = 0; i < NumberOfBullets; i++)
        {
            if (Accuracy < 1)
            {
                float angleX = FMath::RandRange(-1.57f*(1 - Accuracy), 1.57f*(1 - Accuracy));
                float angleY = FMath::RandRange(-1.57f*(1 - Accuracy), 1.57f*(1 - Accuracy));
                DirectionVector = (Direction + FQuat(angleX, angleY, 0.f, 0.f)).Vector();
            }
            else
            {
                DirectionVector = Direction.Vector();
            }

            EndLocation = Location + DirectionVector * Distance;

            const FName TraceTag("MyTraceTag");

            World->DebugDrawTraceTag = TraceTag;

            FCollisionQueryParams CollisionParams = FCollisionQueryParams::DefaultQueryParam;
            CollisionParams.TraceTag = TraceTag;
            CollisionParams.AddIgnoredActor(GetOwner());

            if (World->LineTraceSingleByChannel(Hit, Location, EndLocation, ECollisionChannel::ECC_Camera, CollisionParams))
            {
                AActor* Owner = GetOwner();
                UGameplayStatics::ApplyPointDamage(Hit.GetActor(), Damage, Hit.Normal, Hit, Owner->GetInstigatorController(), Owner, DamageType);
            }
        }
    }
}

float UTraceWeaponComponent::GetWeaponFiringRange() const
{
    return Distance;
}
