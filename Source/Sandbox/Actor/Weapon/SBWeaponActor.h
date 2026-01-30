// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine

// Plugin

// Game
#include "Actor/SBActor.h"

// Generated
#include "SBWeaponActor.generated.h"

UCLASS()
class ASBWeaponActor : public ASBActor
{
	GENERATED_BODY()
	
public:
	ASBWeaponActor();
	
public:
	virtual void Initialize(const FPrimaryAssetId& InWeaponId, class UStaticMesh* InNewMesh);
	virtual void Deinitialize();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SB|Component")
	TObjectPtr<UStaticMeshComponent> WeaponMeshComponent;
	
protected:
	UPROPERTY(Transient)
	FPrimaryAssetId WeaponId;
};