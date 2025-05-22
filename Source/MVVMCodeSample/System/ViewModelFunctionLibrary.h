#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViewModelFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EViewModelContext:uint8
{
	Health,
	ShootState,
};

/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UViewModelFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="MVVM|Context")
	static FName GetContextName(EViewModelContext Context);
};