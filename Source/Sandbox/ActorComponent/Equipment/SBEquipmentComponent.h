// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine

// Plugin

// Game
#include "ActorComponent/SBActorComponent.h"

// Generated
#include "SBEquipmentComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class USBEquipmentComponent : public USBActorComponent
{
	GENERATED_BODY()
	
public:
	void EquipWeaon(const FPrimaryAssetId& InWeaponId, const FName& InWeaponAttachSocket);
	
protected:
	void OnWeaponDataLoaded(const FPrimaryAssetId InWeaponId);
	void OnWeaponMeshLoaded(const class USBWeaponDataAsset* const InDataAsset);
};