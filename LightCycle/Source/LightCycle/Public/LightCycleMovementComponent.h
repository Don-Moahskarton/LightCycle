

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "LightCycleMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTCYCLE_API ULightCycleMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

	

protected:

	//Init
	virtual void InitializeComponent() override;

	//Tick
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
