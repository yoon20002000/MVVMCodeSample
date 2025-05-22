// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVMViewModelSubSystem.h"

#include "MVVMGameSubsystem.h"
#include "MVVMCodeSample/UI/ViewModel/VM_Health.h"

void UMVVMViewModelSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMVVMViewModelSubSystem::Deinitialize()
{
	Super::Deinitialize();
}

UMVVMViewModelBase* UMVVMViewModelSubSystem::CreateViewModel(const FMVVMViewModelContext& InContext, const  UClass* InViewModelClass)
{
	UMVVMViewModelCollectionObject* ViewModelCollection = GetViewModelCollection();
	if (ViewModelCollection == nullptr)
	{
		return nullptr;
	}
	UMVVMViewModelBase* NewViewModel = NewObject<UMVVMViewModelBase>(this, InViewModelClass);
	if (ViewModelCollection->AddViewModelInstance(InContext, NewViewModel) == false)
	{
		return nullptr;
	}
	return NewViewModel;
}

UMVVMViewModelBase* UMVVMViewModelSubSystem::GetViewModel(const FName& InContextName, const UMVVMViewModelBase* InViewModelClass) const
{
	if (UMVVMViewModelCollectionObject* ViewModelCollection = GetViewModelCollection())
	{
		UMVVMViewModelBase* ViewModel = ViewModelCollection->FindViewModelInstance(CreateViewModelContext(InContextName, InViewModelClass));

		return ViewModel;	
	}

	return nullptr;
}

bool UMVVMViewModelSubSystem::RemoveViewModel(const FName& InContextName, const UMVVMViewModelBase* InViewModelClass)
{
	if (UMVVMViewModelCollectionObject* ViewModelCollection = GetViewModelCollection())
	{
		return ViewModelCollection->RemoveViewModel(CreateViewModelContext(InContextName, InViewModelClass));	
	}

	return false;
}

UMVVMGameSubsystem* UMVVMViewModelSubSystem::GetMVVMSubsystem() const
{
	return GetGameInstance()->GetSubsystem<UMVVMGameSubsystem>();
}

UMVVMViewModelCollectionObject* UMVVMViewModelSubSystem::GetViewModelCollection() const
{
	return GetMVVMSubsystem()->GetViewModelCollection();
}

FMVVMViewModelContext UMVVMViewModelSubSystem::CreateViewModelContext(const FName& InContextName,
	const UMVVMViewModelBase* InViewModelClass) const
{
	FMVVMViewModelContext Context;
	Context.ContextClass = InViewModelClass->StaticClass();
	Context.ContextName = InContextName;
	return Context;
}
