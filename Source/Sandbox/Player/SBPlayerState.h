// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"

// Plugin

// Game
#include "AbilitySystem/SBAbilitySystemComponent.h"

// Generated
#include "SBPlayerState.generated.h"

UCLASS(abstract)
class ASBPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASBPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override {return AbilitySystemComponent; }

protected:
	UPROPERTY()
	TObjectPtr<class USBAbilitySystemComponent> AbilitySystemComponent = nullptr;
};