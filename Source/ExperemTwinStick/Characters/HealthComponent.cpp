

#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UHealthComponent::DamageBy(float AmountOfDamage)
{
    CurrentHealth -= AmountOfDamage;
    TimeToStartHeal = HealDelay;
    return CurrentHealth < 0;
}

float UHealthComponent::GetHealthPercent() const
{
    return (MaxHealth == 0.f) ? 0 : (CurrentHealth / MaxHealth);
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
    if (TimeToStartHeal < 0)
    {
        CurrentHealth = FMath::Min(MaxHealth, CurrentHealth + DeltaTime * HealSpeed);
    }
    else
    {
        TimeToStartHeal -= DeltaTime * HealSpeed;
    }
}
