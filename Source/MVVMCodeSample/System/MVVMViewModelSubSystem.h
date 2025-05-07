// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Types/MVVMViewModelContext.h"
#include "MVVMViewModelSubSystem.generated.h"

class UMVVMViewModelCollectionObject;
class UMVVMGameSubsystem;
class UMVVMViewModelBase;
/**
 * 
 */
UCLASS()
class MVVMCODESAMPLE_API UMVVMViewModelSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UMVVMViewModelBase* CreateViewModel(const FMVVMViewModelContext& InContext,const UClass* InViewModelClass);
	UMVVMViewModelBase* GetViewModel(const FName& InContextName,const UMVVMViewModelBase* InViewModelClass) const;
	bool RemoveViewModel(const FName& InContextName, const UMVVMViewModelBase* InViewModelClass);
	
private:
	UMVVMGameSubsystem* GetMVVMSubsystem() const;
	UMVVMViewModelCollectionObject* GetViewModelCollection() const;
	FMVVMViewModelContext CreateViewModelContext(const FName& InContextName, const UMVVMViewModelBase* InViewModelClass) const;
	
};
