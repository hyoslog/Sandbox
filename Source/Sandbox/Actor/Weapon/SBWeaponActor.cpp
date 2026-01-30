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

void ASBWeaponActor::Initialize(const FPrimaryAssetId& InWeaponId, UStaticMesh* InNewMesh)
{
	WeaponId = InWeaponId;
	
	check(WeaponMeshComponent);
	WeaponMeshComponent->SetStaticMesh(InNewMesh);
	
	// TODO: 충돌 채널 변경
	WeaponMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));
}

void ASBWeaponActor::Deinitialize()
{
	WeaponId = FPrimaryAssetId();
}
