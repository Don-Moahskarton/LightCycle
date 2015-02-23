

#include "LightCycle.h"
#include "LightCycleMovementComponent.h"


ULightCycleMovementComponent::ULightCycleMovementComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void ULightCycleMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void ULightCycleMovementComponent::TickComponent( float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
