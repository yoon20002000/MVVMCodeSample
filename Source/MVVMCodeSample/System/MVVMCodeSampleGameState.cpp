// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVMCodeSampleGameState.h"

void AMVVMCodeSampleGameState::SetShootCount(float InShootCount)
{
	ShootCount = FMath::Clamp(InShootCount, 0, InShootCount);
	OnShootCountChanged.Broadcast(ShootCount);
}

float AMVVMCodeSampleGameState::GetShootCount() const
{
	return ShootCount;
}

void AMVVMCodeSampleGameState::SetHitCount(float InHitCount)
{
	HitCount = FMath::Clamp(InHitCount, 0, InHitCount);
	OnHitCountChanged.Broadcast(HitCount);
}

float AMVVMCodeSampleGameState::GetHitCount() const
{
	return HitCount;
}
