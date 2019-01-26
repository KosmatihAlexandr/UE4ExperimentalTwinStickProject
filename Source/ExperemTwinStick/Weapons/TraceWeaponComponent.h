

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeaponComponent.h"
#include "TraceWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class EXPEREMTWINSTICK_API UTraceWeaponComponent : public UBaseWeaponComponent
{
	GENERATED_BODY()
	
public:
    virtual float GetWeaponFiringRange() const override;

protected:
    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float Distance = 300.f;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    int NumberOfBullets = 1;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float Accuracy = 1.f;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    float Damage = 1.f;

    UPROPERTY(Category = "Weapon stats", BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UDamageType> DamageType;

    virtual void Shoot(FVector Location, FQuat Direction) override;

    UFUNCTION(BlueprintImplementableEvent)
    void ShootEffect(FVector Start, FVector End) const;
};
