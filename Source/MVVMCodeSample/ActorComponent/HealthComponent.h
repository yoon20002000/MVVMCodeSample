// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChanged, float, maxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MVVMCODESAMPLE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Health Point Section
public:
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnMaxHealthChanged OnMaxHealthChanged;

	UFUNCTION()
	void AddHealth(float AddHealth);
	UFUNCTION()
	void SetHealth(float InHealth);
	UFUNCTION()
	float GetHealth() const;
	UFUNCTION()
	void AddMaxHealth(float AddMaxHealth);
	UFUNCTION()
	void SetMaxHealth(float InMaxHealth);
	UFUNCTION()
	float GetMaxHealth() const;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float MaxHealth;
	//
};
