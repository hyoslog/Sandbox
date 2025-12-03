// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBPlayerState.h"

// ThirdParty

// Engine

// Plugin

// Game

ASBPlayerState::ASBPlayerState(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<USBAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
	check(AbilitySystemComponent);
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

}