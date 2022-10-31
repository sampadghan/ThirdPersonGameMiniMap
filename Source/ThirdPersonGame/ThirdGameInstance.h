// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyInterface.h"
#include "Engine/Engine.h"
#include "ThirdGameInstance.generated.h"

/**
 *
 */
UCLASS()
class THIRDPERSONGAME_API UThirdGameInstance : public UGameInstance,public IMyInterface
{
	GENERATED_BODY()

public:
	UThirdGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
		void ShowWidget() override;

	TSubclassOf<class UUserWidget> MenuClass;
	//My Function
	UFUNCTION(Exec)
		void ShowMiniMap() override;

};
