// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVMCodeSampleGameMode.h"
#include "MVVMCodeSampleCharacter.h"
#include "UI/UI_Battle.h"
#include "UObject/ConstructorHelpers.h"

AMVVMCodeSampleGameMode::AMVVMCodeSampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
