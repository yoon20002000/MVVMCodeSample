// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMUserWidget.h"
#include "UI_HealthBar.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UUI_HealthBar : public UMVVMUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void SetHealthBarPercentage(float InHealthPercentage);
private:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UProgressBar> PB_HealthBar;
};
