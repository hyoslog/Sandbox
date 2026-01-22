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
	class USpringArmComponent* GetCameraBoom() const { return CameraBoomComponent; }
	class UCameraComponent* GetFollowCamera() const { return FollowCameraComponent; }

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InPlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	void OnMove(const struct FInputActionValue& InValue);
	void OnLook(const struct FInputActionValue& InValue);

protected:
	virtual void DoMove(float Right, float Forward);
	virtual void DoLook(float Yaw, float Pitch);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SB|Component")
	TObjectPtr<class USpringArmComponent> CameraBoomComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SB|Component")
	TObjectPtr<class UCameraComponent> FollowCameraComponent = nullptr;

protected:
	UPROPERTY(EditAnywhere, Category="SB|Input")
	TObjectPtr<class UInputAction> JumpAction = nullptr;

	UPROPERTY(EditAnywhere, Category="SB|Input")
	TObjectPtr<class UInputAction> MoveAction = nullptr;

	UPROPERTY(EditAnywhere, Category="SB|Input")
	TObjectPtr<class UInputAction> LookAction = nullptr;

	UPROPERTY(EditAnywhere, Category="SB|Input")
	TObjectPtr<class UInputAction> MouseLookAction = nullptr;
	
protected:
	UPROPERTY(EditAnywhere, Category="SB|Weapon")
	FName WeaponSocket;
};