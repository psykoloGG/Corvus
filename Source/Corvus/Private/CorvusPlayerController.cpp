#include "CorvusPlayerController.h"

#include "CorvusGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Menus/MenusWidget.h"
#include "ObjectViewer/ObjectViewerWidget.h"

void ACorvusPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UCorvusGameInstance* GameInstance = Cast<UCorvusGameInstance>(GetGameInstance());
	GameInstance->InitMainUI();
}

ACorvusPlayerController::ACorvusPlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	PossessedCameras = TArray<ACameraActor*>();
}

void ACorvusPlayerController::SetupForLevel()
{
	if (PossessedCameras.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("No cameras possessed by player"));
		return;
	}

	SetViewTarget(PossessedCameras[0]);
	bShouldRaycast = true;
}
