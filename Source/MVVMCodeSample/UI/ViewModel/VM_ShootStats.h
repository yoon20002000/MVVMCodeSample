// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_ShootStats.generated.h"

/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UVM_ShootStats : public UMVVMViewModelBase
{
	GENERATED_BODY()
public:
	UVM_ShootStats();
private:
/// Shoot Stats
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	int32 ShootCount;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	int32 HitCount;

public:
	void SetShootCount(const int32 InShootCount)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(ShootCount, InShootCount))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHitPercentage);
		}
	}
	
	int32 GetShootCount() const
	{
		return ShootCount;
	}

	void SetHitCount(const int32 InHitCount)
	{
		if (UE_MVVM_SET_PROPERTY_VALUE(HitCount, InHitCount))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHitPercentage);
		}
	}

	int32 GetHitCount() const
	{
		return HitCount;
	}
	
	UFUNCTION(BlueprintPure, FieldNotify)
	FText GetHitPercentage() const
	{
		if (ShootCount != 0)
		{
			return FText::FromString(FString::Printf(TEXT("%.2f%%"), (static_cast<float>(HitCount) / ShootCount)));
		}
		else
		{
			return FText::AsNumber(0);
		}
	}
///
};
