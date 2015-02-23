// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "LightCycleHUD.generated.h"

UCLASS()
class ALightCycleHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

public:

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	/** Font to use for generic text */
	UFont* mFont;

};

