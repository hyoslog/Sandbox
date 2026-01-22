// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBWeaponActor.h"

// ThirdParty

// Engine

// Plugin

// Game
ASBWeaponActor::ASBWeaponActor()
{
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	check(SceneComponent);
	SetRootComponent(SceneComponent);
	
	WeaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	check(WeaponMeshComponent);
	WeaponMeshComponent->SetupAttachment(SceneComponent);
}