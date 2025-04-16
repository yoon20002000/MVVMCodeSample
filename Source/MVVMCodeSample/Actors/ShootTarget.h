// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootTarget.generated.h"

class UHealthComponent;

UCLASS()
class MVVMCODESAMPLE_API AShootTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// Static Mesh Actor
	UPROPERTY(EditAnywhere, Category= Mesh)
	TObjectPtr<UStaticMeshComponent> MeshComponent;
//
	
// Health Section
	TObjectPtr<UHealthComponent> HealthComponent;
//
};
