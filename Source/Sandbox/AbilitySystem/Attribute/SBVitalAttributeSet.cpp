// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBVitalAttributeSet.h"

// ThirdParty

// Engine
#include "Net/UnrealNetwork.h"

// Plugin

// Game

void USBVitalAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHealth, COND_None, REPNOTIFY_Always);
}

void USBVitalAttributeSet::OnRep_Health(const FGameplayAttributeData& InOldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, InOldHealth);
}

void USBVitalAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& InOldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHealth, InOldMaxHealth);	
}