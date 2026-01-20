// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"
#include "SBAttributeSet.h"

// ThirdParty

// Engine

// Plugin

// Game

// Generated
#include "SBVitalAttributeSet.generated.h"

/**
 * Getter, Setter, Init 함수 생성
 */
#define SB_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class USBVitalAttributeSet : public USBAttributeSet
{
	GENERATED_BODY()
};