// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBuilder.h"
#include "BaseBuilderPlayerController.h"
#include "GameHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"

AGameHUD::AGameHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontObj(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	Font = HUDFontObj.Object;
}


void AGameHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawHealth();
	DrawResources();
	DrawSelect();
}

void AGameHUD::DrawHealth()
{
	ABaseBuilderPlayerController * Player = Cast<ABaseBuilderPlayerController>(GetWorld()->GetFirstPlayerController());

	int Health = Player->Health;

	FString Text = "Health: " + FString::SanitizeFloat(Health);

	FText SomeText = FText::FromString(Text);

	float XPosition = Canvas->ClipX*0.85f;
	float YPosition = Canvas->ClipY*0.1f;

	FLinearColor TheFontColour = FLinearColor(0.0f, 0.0f, 0.0f);
	FCanvasTextItem NewText(FVector2D(XPosition, YPosition), SomeText, Font, TheFontColour);

	//Text Scale
	NewText.Scale.Set(1, 1);

	//Draw
	Canvas->DrawItem(NewText);
}

void AGameHUD::DrawResources()
{
	ABaseBuilderPlayerController * Player = Cast<ABaseBuilderPlayerController>(GetWorld()->GetFirstPlayerController());

	int Resources = Player->Money;

	FString Text = "Resources: " + FString::SanitizeFloat(Resources);

	FText SomeText = FText::FromString(Text);

	float XPosition = Canvas->ClipX *0.01;
	float YPosition = Canvas->ClipY*0.05f;

	FLinearColor TheFontColour = FLinearColor(0.0f, 0.0f, 0.0f);
	FCanvasTextItem NewText(FVector2D(XPosition, YPosition), SomeText, Font, TheFontColour);

	//Text Scale
	NewText.Scale.Set(1, 1);

	//Draw
	Canvas->DrawItem(NewText);
}

void AGameHUD::DrawSelect()
{
	ABaseBuilderPlayerController * Player = Cast<ABaseBuilderPlayerController>(GetWorld()->GetFirstPlayerController());

	int Resources = Player->Money;

	FString Text = "Description: " + FString::SanitizeFloat(Resources);

	FText SomeText = FText::FromString(Text);

	float XPosition = Canvas->ClipX *0.01;
	float YPosition = Canvas->ClipY*0.85f;

	FLinearColor TheFontColour = FLinearColor(0.0f, 0.0f, 0.0f);
	FCanvasTextItem NewText(FVector2D(XPosition, YPosition), SomeText, Font, TheFontColour);

	//Text Scale
	NewText.Scale.Set(1, 1);

	//Draw
	Canvas->DrawItem(NewText);
}