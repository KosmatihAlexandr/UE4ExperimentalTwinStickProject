

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Health), meta=(BlueprintSpawnableComponent) )
class EXPEREMTWINSTICK_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

    UFUNCTION(Category = "Damaging", BlueprintCallable)
    bool DamageBy(float AmountOfDamage);

    UFUNCTION(Category = "Health", BlueprintCallable)
    float GetHealthPercent() const;

protected:
    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;

    UPROPERTY(Category = "Health", BlueprintReadWrite, EditDefaultsOnly)
    float MaxHealth;

    UPROPERTY(Category = "Health", BlueprintReadWrite, EditDefaultsOnly)
    float HealDelay = 10.f;

    UPROPERTY(Category = "Health", BlueprintReadWrite, EditDefaultsOnly)
    float HealSpeed = 1.f;

private:
    float CurrentHealth;

    float TimeToStartHeal;

};
