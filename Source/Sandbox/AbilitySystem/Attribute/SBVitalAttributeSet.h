// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "AbilitySystemComponent.h"
#include "SBAttributeSet.h"

// Plugin

// Game

// Generated
#include "SBVitalAttributeSet.generated.h"

UCLASS()
class USBVitalAttributeSet : public USBAttributeSet
{
	GENERATED_BODY()
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& InOldHealth);
	
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& InOldMaxHealth);

private:
	// 현재 체력
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "SB|Vital", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	SB_ATTRIBUTE_ACCESSORS(USBVitalAttributeSet, Health);
	
	// 최대 체력
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "SB|Vital", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	SB_ATTRIBUTE_ACCESSORS(USBVitalAttributeSet, MaxHealth);
};