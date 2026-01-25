// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "Engine/DataAsset.h"

// Plugin

// Game

// Generated
#include "WeaponDataAsset.generated.h"

UCLASS()
class USBWeaponDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
protected:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("Weapon"), GetFName());
	}
	
protected:	
	UPROPERTY(EditDefaultsOnly)
	FText DisplayName;
	
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UTexture2D> IconImage;
	
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UStaticMesh> WeaponMesh;
};