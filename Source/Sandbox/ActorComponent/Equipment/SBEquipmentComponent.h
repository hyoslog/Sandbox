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
class SANDBOX_API USBEquipmentComponent : public USBActorComponent
{
	GENERATED_BODY()
	
public:
	void EquipWeaon(const FPrimaryAssetId& InWeaponId, const FName& InWeaponAttachSocket);
};