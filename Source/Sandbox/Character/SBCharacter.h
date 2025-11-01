// Copyright hyoslog. All Rights Reserved.

#pragma once

// Default
#include "CoreMinimal.h"

// ThirdParty

// Engine
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"

// Plugin

// Game

// Generated
#include "SBCharacter.generated.h"

UCLASS(abstract)
class ASBCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASBCharacter();

public:
	class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;

protected:
	void OnMove(const struct FInputActionValue& InValue);
	void OnLook(const struct FInputActionValue& InValue);

protected:
	virtual void DoMove(float Right, float Forward);
	virtual void DoLook(float Yaw, float Pitch);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USpringArmComponent* CameraBoom = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UCameraComponent* FollowCamera = nullptr;

protected:
	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* JumpAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MoveAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* LookAction = nullptr;

	UPROPERTY(EditAnywhere, Category="Input")
	class UInputAction* MouseLookAction = nullptr;
};