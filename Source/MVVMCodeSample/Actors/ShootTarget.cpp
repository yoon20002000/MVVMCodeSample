// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTarget.h"

#include "MVVMCodeSample/ActorComponent/HealthComponent.h"

// Sets default values
AShootTarget::AShootTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
// Health Section
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
//
}

// Called when the game starts or when spawned
void AShootTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

