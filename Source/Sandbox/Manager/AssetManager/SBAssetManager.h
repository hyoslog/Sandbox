// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "Engine/AssetManager.h"

// Plugin

// Game

// Generated
#include "SBAssetManager.generated.h"

UCLASS()
class USBAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static UAssetManager& Get();
	
public:
	virtual void StartInitialLoading() override;
};
