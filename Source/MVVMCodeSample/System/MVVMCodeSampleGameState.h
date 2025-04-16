// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MVVMCodeSampleGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShootCountChanged, float, ShootCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitCountChanged, float, HitCount);
/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API AMVVMCodeSampleGameState : public AGameState
{
	GENERATED_BODY()

	// Shoot Stats Section
public:
	void SetShootCount(float InShootCount);
	float GetShootCount() const;
	void SetHitCount(float InHitCount);
	float GetHitCount() const;

	FOnShootCountChanged OnShootCountChanged;
	FOnHitCountChanged OnHitCountChanged;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ShootStats, meta = (AllowPrivateAccess = "true"))
	float ShootCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ShootStats, meta = (AllowPrivateAccess = "true"))
	float HitCount;
	// 
};
