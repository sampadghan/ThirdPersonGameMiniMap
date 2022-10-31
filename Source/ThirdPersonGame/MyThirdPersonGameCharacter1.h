// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonGameCharacter.h"
#include "Engine/World.h"
#include "MyThirdPersonGameCharacter1.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API AMyThirdPersonGameCharacter1 : public AThirdPersonGameCharacter
{
	GENERATED_BODY()
public:
	AMyThirdPersonGameCharacter1();
	virtual void BeginPlay() override;
};
