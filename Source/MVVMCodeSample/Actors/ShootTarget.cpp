// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTarget.h"

#include "MVVMCodeSample/MVVMCodeSampleCollision.h"
#include "MVVMCodeSample/ActorComponent/HealthComponent.h"

// Sets default values
AShootTarget::AShootTarget()
{
	PrimaryActorTick.bCanEverTick = false;
// Static Mesh Actor
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	MeshComponent->SetCollisionProfileName(CPROFILE_PHYSICSACTOR);
	MeshComponent->SetSimulatePhysics(true);
//
	
// Health Section
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
//
}

// Called when the game starts or when spawned
void AShootTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

