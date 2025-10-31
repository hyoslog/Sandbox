// Copyright hyoslog. All Rights Reserved.

// Default
#include "SBCharacter.h"

// ThirdParty

// Plugin

// Engine
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Game

ASBCharacter::ASBCharacter()
{
	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	check(CapsuleComp);
	CapsuleComp->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* CharMoveComp = GetCharacterMovement();
	check(CharMoveComp);
	CharMoveComp->bOrientRotationToMovement = true;
	CharMoveComp->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	CharMoveComp->JumpZVelocity = 500.f;
	CharMoveComp->AirControl = 0.35f;
	CharMoveComp->MaxWalkSpeed = 500.f;
	CharMoveComp->MinAnalogWalkSpeed = 20.f;
	CharMoveComp->BrakingDecelerationWalking = 2000.f;
	CharMoveComp->BrakingDecelerationFalling = 1500.0f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	check(CameraBoom);
	check(RootComponent);
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	check(FollowCamera);
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ASBCharacter::SetupPlayerInputComponent(UInputComponent* InPlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(InPlayerInputComponent);
	if (IsValid(EnhancedInputComp) == false)
	{
		ensure(false);
		return;
	}

	// Jump
	ensure(JumpAction);
	EnhancedInputComp->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
	EnhancedInputComp->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

	// Move
	ensure(MoveAction);
	EnhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASBCharacter::OnMove);

	// Look
	ensure(MouseLookAction);
	EnhancedInputComp->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ASBCharacter::OnLook);
	ensure(LookAction);
	EnhancedInputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASBCharacter::OnLook);
}


void ASBCharacter::OnMove(const FInputActionValue& InValue)
{
	const FVector2D MovementVector = InValue.Get<FVector2D>();

	DoMove(MovementVector.X, MovementVector.Y);
}

void ASBCharacter::OnLook(const FInputActionValue& InValue)
{
	const FVector2D LookAxisVector = InValue.Get<FVector2D>();

	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void ASBCharacter::DoMove(float Right, float Forward)
{
	const AController* const CharCtrl = GetController();
	if (IsValid(CharCtrl) == false)
	{
		ensure(false);
		return;
	}

	const FRotator Rotation = CharCtrl->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, Forward);
	AddMovementInput(RightDirection, Right);
}

void ASBCharacter::DoLook(float Yaw, float Pitch)
{
	AddControllerYawInput(Yaw);
	AddControllerPitchInput(Pitch);
}