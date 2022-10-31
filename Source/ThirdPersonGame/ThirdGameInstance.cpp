// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

UThirdGameInstance::UThirdGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Inside GameInstance Constructor"));
	static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/MiniMap_T"));
	if (!ensure(MenuBPClass.Class != nullptr))return;
	MenuClass = MenuBPClass.Class;
}
void UThirdGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

void UThirdGameInstance::ShowWidget()
{
	if (!ensure(MenuClass != nullptr)) return;
	UUserWidget* Menu = CreateWidget<UUserWidget>(this, MenuClass);

	if (!ensure(Menu != nullptr)) return;
	Menu->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	FInputModeGameAndUI InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}
void UThirdGameInstance::ShowMiniMap()
{
	if (!ensure(MenuClass != nullptr))
	{
		return;
	}
	UUserWidget* Menu = CreateWidget<UUserWidget>(this, MenuClass);
	if (!ensure(Menu != nullptr))
	{
		return;
	}
	Menu->AddToViewport();
	GetEngine()->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Showing"));
}