// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "LightCycle.h"
#include "LightCycleCharacter.h"
#include "LightCycleProjectile.h"
#include "Animation/AnimInstance.h"
#include "LightCycleMovementComponent.h"


//////////////////////////////////////////////////////////////////////////
// ALightCycleCharacter

ALightCycleCharacter::ALightCycleCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP.SetDefaultSubobjectClass<ULightCycleMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	
	// gampley dependant : initial speed
	requestedMovementSpeed = 0.0f;
	movementAccelerationRate = 2.0f;

	// gampley dependant: light wall initialisation
	isGeneraingTail = true;

	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	
	// Create a CameraComponent	
	FirstPersonCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = CapsuleComponent;
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = PCIP.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->RelativeLocation = FVector(0.f, 0.f, -150.f);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;


	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALightCycleCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{

	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("TailToggle", IE_Pressed, this, &ACharacter::Jump);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &ALightCycleCharacter::OnToggleTail);
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ALightCycleCharacter::TouchStarted);

	InputComponent->BindAxis("MoveForward", this, &ALightCycleCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ALightCycleCharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &ALightCycleCharacter::TurnAbsolute);
	InputComponent->BindAxis("TurnRate", this, &ALightCycleCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &ALightCycleCharacter::LookUpAbsolute);
	InputComponent->BindAxis("LookUpRate", this, &ALightCycleCharacter::LookUpAtRate);
}

// enable or dsable the lightwall
void ALightCycleCharacter::OnToggleTail()
{
	isGeneraingTail = !isGeneraingTail;

	//// try and fire a projectile
	//if (ProjectileClass != NULL)
	//{
	//	const FRotator SpawnRotation = GetControlRotation();
	//	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	//	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

	//	UWorld* const World = GetWorld();
	//	if (World != NULL)
	//	{
	//		// spawn the projectile at the muzzle
	//		World->SpawnActor<ALightCycleProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
	//	}
	//}

	//// try and play the sound if specified
	//if (FireSound != NULL)
	//{
	//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	//}

	//// try and play a firing animation if specified
	//if(FireAnimation != NULL)
	//{
	//	// Get the animation object for the arms mesh
	//	UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
	//	if(AnimInstance != NULL)
	//	{
	//		AnimInstance->Montage_Play(FireAnimation, 1.f);
	//	}
	//}

}


void ALightCycleCharacter::Tick(float deltaTime)
{
	// move the light cycle lengthwise proportionnally to it's current speed
	AddMovementInput(GetActorForwardVector(), requestedMovementSpeed);

	
}

void ALightCycleCharacter::updateLocationHistoryOnTick()
{
	LightCycleLocationHistorySlot historySlotToAdd = *(new LightCycleLocationHistorySlot());
	historySlotToAdd.position = GetActorLocation();
	historySlotToAdd.timestamp = FPlatformTime::Seconds();
	locationHistory.Add(historySlotToAdd);
	
}

void ALightCycleCharacter::handleTailGenerationOnTick()
{

}

void ALightCycleCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// only fire for first finger down
	if (FingerIndex == 0)
	{
		OnToggleTail();
	}
}

void ALightCycleCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		requestedMovementSpeed += Value * movementAccelerationRate * GetWorld()->GetDeltaSeconds();
	}
}

void ALightCycleCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	}
}


void ALightCycleCharacter::TurnAbsolute(float Rate)
{
	FirstPersonCameraComponent->AddRelativeRotation(
		FRotator(	0.0f,
					4 * Rate
					, 0.0f
				)
	);
}


void ALightCycleCharacter::LookUpAbsolute(float Rate)
{
	FirstPersonCameraComponent->AddRelativeRotation(
			FRotator(-4 * Rate,
			0.0f,
			0.0f
			)
		);
}


void ALightCycleCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
//	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ALightCycleCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
