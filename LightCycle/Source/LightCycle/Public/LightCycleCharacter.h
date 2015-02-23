// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "LightCycleCharacter.generated.h"

/**
 * Describes a loation reached by the LightCycle at a certain date
 */
struct LightCycleLocationHistorySlot
{
	/** the position to register*/
	FVector position;

	/** date at which the lightcycle was there*/
	double timestamp;
};



/**
 * Main class of the LightCycle. 
 */
UCLASS(config=Game)
class ALightCycleCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* FirstPersonCameraComponent;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ALightCycleProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	/** Ticking function of the LightCycle Character */
	virtual void Tick(float DeltaSeconds) override;
	
protected:

	/** indicate if the lightwall generation is currently active or not*/
	bool isGeneraingTail;

	/** called on tick to generate the lightwall behind the lightcycle*/
	void handleTailGenerationOnTick();

	/** History of previous location that the lightcycle reached */
	TArray<struct LightCycleLocationHistorySlot> locationHistory;

	/** called on tick to update the location history*/
	void updateLocationHistoryOnTick();

	/** The current speed the user request the lightcycle to move */
	float requestedMovementSpeed;

	/** The rate at which the speed requested by the user can variate*/
	float movementAccelerationRate;

	/** Handler for a touch input beginning. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Enable or disable the tail */
	void OnToggleTail();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);


	void TurnAbsolute(float Rate);

	void LookUpAbsolute(float Rate);


	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
};

