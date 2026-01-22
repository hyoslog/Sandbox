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
class SANDBOX_API ASBWeaponActor : public ASBActor
{
	GENERATED_BODY()
	
public:
	ASBWeaponActor();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SB|Component")
	TObjectPtr<UStaticMeshComponent> WeaponMeshComponent;
};