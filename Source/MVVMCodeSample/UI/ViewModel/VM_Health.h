// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_Health.generated.h"

/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UVM_Health : public UMVVMViewModelBase
{
	GENERATED_BODY()
public:
	UVM_Health();
/// Health Section
private:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	float CurHealth;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	float MaxHealth;

public:
	void SetCurHealth(const float InCurHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(CurHealth, InCurHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercentage);
		}
	}
	float GetCurHealth() const
	{
		return CurHealth;
	}

	void SetMaxHealth(const float InMaxHealth)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, InMaxHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercentage);
		}
	}

	float GetMaxHealth() const
	{
		return MaxHealth;
	}

	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercentage() const
	{
		if (MaxHealth != 0)
		{
			return CurHealth / MaxHealth;
		}
		else
		{
			return 0;
		}
	}
///
};
