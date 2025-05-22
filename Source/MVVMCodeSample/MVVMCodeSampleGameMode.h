// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MVVMCodeSampleGameMode.generated.h"

class UUI_Battle;

UCLASS(minimalapi)
class AMVVMCodeSampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMVVMCodeSampleGameMode();
private:
	UPROPERTY(EditAnywhere, meta=(allowPrivateAccess=true))
	TSoftClassPtr<UUI_Battle> UIBattle;
};



