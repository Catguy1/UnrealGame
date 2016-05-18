// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class BASEBUILDER_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY()
		const UFont *Font;

private:
	
	void DrawHealth();

	void DrawResources();

	void DrawSelect();
};
