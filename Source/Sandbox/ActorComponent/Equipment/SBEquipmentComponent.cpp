// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBEquipmentComponent.h"

#include "Actor/Weapon/SBWeaponActor.h"
#include "Character/SBCharacter.h"

// ThirdParty

// Engine

// Plugin

// Game

void USBEquipmentComponent::EquipWeaon(const FPrimaryAssetId& InWeaponId, const FName& InWeaponAttachSocket)
{	
	ASBCharacter* OwnerCharacter = Cast<ASBCharacter>(GetOwner());
	if (IsValid(OwnerCharacter) == false)
	{
		ensure(false);
		return;
	}
	
	UWorld* World = OwnerCharacter->GetWorld();
	check(World);
	
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = OwnerCharacter;
	SpawnInfo.Instigator = OwnerCharacter;
	
	ASBWeaponActor* NewWeaponActor = World->SpawnActor<ASBWeaponActor>(ASBWeaponActor::StaticClass(), SpawnInfo);
	check(NewWeaponActor);
	
	// 캐릭터 소켓에 부착
	NewWeaponActor->AttachToComponent(
		OwnerCharacter->GetMesh(), 
		FAttachmentTransformRules::SnapToTargetNotIncludingScale, 
		InWeaponAttachSocket
	);
}