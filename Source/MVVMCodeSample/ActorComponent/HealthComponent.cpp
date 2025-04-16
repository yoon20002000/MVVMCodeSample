// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetMaxHealth(100);
	SetHealth(MaxHealth);
	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UHealthComponent::AddHealth(float AddHealth)
{
	SetHealth(Health + AddHealth);
}
void UHealthComponent::SetHealth(float InHealth)
{
	Health = FMath::Clamp(InHealth, 0.0f, MaxHealth);

	OnHealthChanged.Broadcast(Health);
}

float UHealthComponent::GetHealth() const
{
	return Health;
}

void UHealthComponent::AddMaxHealth(float AddMaxHealth)
{
	SetMaxHealth(MaxHealth + AddMaxHealth);
}

void UHealthComponent::SetMaxHealth(float InMaxHealth)
{
	MaxHealth = InMaxHealth;
	
	OnMaxHealthChanged.Broadcast(InMaxHealth);
}

float UHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}
