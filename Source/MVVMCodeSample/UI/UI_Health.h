// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMUserWidget.h"
#include "UI_Health.generated.h"

class UTextBlock;
class UUI_HealthBar;
/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UUI_Health : public UMVVMUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void UpdateHealth(float InHealth, float InMaxHealth);

private:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UTextBlock> TXT_HealthPoint;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UUI_HealthBar> HealthBar;
};
