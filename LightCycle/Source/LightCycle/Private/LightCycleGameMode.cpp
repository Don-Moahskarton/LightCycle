// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "LightCycle.h"
#include "LightCycleGameMode.h"
#include "LightCycleHUD.h"
#include "LightCycleCharacter.h"

ALightCycleGameMode::ALightCycleGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALightCycleHUD::StaticClass();
}
