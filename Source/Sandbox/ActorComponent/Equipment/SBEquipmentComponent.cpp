// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBEquipmentComponent.h"

#include "Actor/Weapon/SBWeaponActor.h"
#include "Character/SBCharacter.h"
#include "Data/DataAsset/WeaponDataAsset.h"
#include "Manager/AssetManager/SBAssetManager.h"

// ThirdParty

// Engine

// Plugin

// Game

void USBEquipmentComponent::EquipWeaon(const FPrimaryAssetId& InWeaponId, const FName& InWeaponAttachSocket)
{
	USBAssetManager& AssetManager = USBAssetManager::Get();
	
	if (const auto* const WeaponData = Cast<USBWeaponDataAsset>(AssetManager.GetPrimaryAssetObject(InWeaponId)))
	{
		OnWeaponDataLoaded(InWeaponId);
	}
	else
	{
		AssetManager.LoadPrimaryAssets({InWeaponId}, 
			TArray<FName>(), 
			FStreamableDelegate::CreateUObject(this, &ThisClass::OnWeaponDataLoaded, InWeaponId)
		);
	}
}

void USBEquipmentComponent::OnWeaponDataLoaded(const FPrimaryAssetId InWeaponId)
{
	const UAssetManager& AssetManager = UAssetManager::Get();
	
	const auto* const WeaponData = Cast<USBWeaponDataAsset>(AssetManager.GetPrimaryAssetObject(InWeaponId));
	check(WeaponData);

	if (WeaponData->WeaponMesh.IsValid())
	{
		OnWeaponMeshLoaded(WeaponData);
	}
	else
	{
		AssetManager.GetStreamableManager().RequestAsyncLoad(
			WeaponData->WeaponMesh.ToSoftObjectPath(),
			FStreamableDelegate::CreateUObject(this, &ThisClass::OnWeaponMeshLoaded, WeaponData)
		);
	}
}

void USBEquipmentComponent::OnWeaponMeshLoaded(const USBWeaponDataAsset* const InDataAsset)
{
	check(InDataAsset);
	
	UWorld* World = GetWorld();
	check(World);
	
	ASBCharacter* OwnerCharacter = Cast<ASBCharacter>(GetOwner());
	if (IsValid(OwnerCharacter) == false)
	{
		ensure(false);
		return;
	}

	UStaticMesh* LoadedMesh = InDataAsset->WeaponMesh.Get();
	if (LoadedMesh == nullptr)
	{
		ensure(false);
		return;
	}
	
	auto* NewWeaponActor = World->SpawnActorDeferred<ASBWeaponActor>(ASBWeaponActor::StaticClass(), FTransform::Identity, GetOwner());
	check(NewWeaponActor);
	
	NewWeaponActor->Initialize(InDataAsset->GetPrimaryAssetId(), LoadedMesh);
	NewWeaponActor->FinishSpawning(FTransform::Identity);
	NewWeaponActor->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("hand_r"));
}