// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBPlayerController.h"

// ThirdParty

// Engine
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Widgets/Input/SVirtualJoystick.h"

// Plugin

// Game

void ASBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IsLocalPlayerController())
	{
		UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if (ensure(IsValid(EnhancedInputSubsys)))
		{
			for (const UInputMappingContext* const CurrentContext : DefaultMappingContexts)
			{
				if (ensure(IsValid(CurrentContext)))
				{
					EnhancedInputSubsys->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}
