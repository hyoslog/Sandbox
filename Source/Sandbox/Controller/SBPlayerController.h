// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "GameFramework/PlayerController.h"

// Plugin

// Game

// Generated
#include "SBPlayerController.generated.h"

UCLASS(abstract)
class ASBPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditAnywhere, Category ="Input")
	TArray<class UInputMappingContext*> DefaultMappingContexts;
};
