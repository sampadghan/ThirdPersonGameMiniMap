// Fill out your copyright notice in the Description page of Project Settings.


#include "MyThirdPersonGameCharacter1.h"
#include "Components/SceneCaptureComponent2D.h"

AMyThirdPersonGameCharacter1::AMyThirdPersonGameCharacter1()
{
	//Super::AThirdPersonGameCharacter();
}
void AMyThirdPersonGameCharacter1::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* MyPlayerController = GetWorld()->GetFirstPlayerController();
	if (RenderTarget)
	{
		if (MyPlayerController->IsLocalController())
		{
			MiniMap->TextureTarget = RenderTarget;
		}
	}
}