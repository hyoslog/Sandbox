// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBAssetManager.h"

// ThirdParty

// Engine

// Plugin

// Game

USBAssetManager& USBAssetManager::Get(){
	check(GEngine);

	if (USBAssetManager* Singleton = Cast<USBAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}
	
	// 호출될 일 없어야 함
	check(false);
	return *NewObject<USBAssetManager>();
}

void USBAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}