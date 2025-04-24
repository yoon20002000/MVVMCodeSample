// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMUserWidget.h"
#include "UI_Battle.generated.h"

class UUI_Health;
/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UUI_Battle : public UMVVMUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta=(BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UUI_Health> Health;
};
