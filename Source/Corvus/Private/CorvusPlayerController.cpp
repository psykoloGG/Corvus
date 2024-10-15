#include "CorvusPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Menus/MenusWidget.h"
#include "ObjectViewer/ObjectViewerWidget.h"

void ACorvusPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!MenusWidgetInstance)
	{
		MenusWidgetInstance = CreateWidget<UMenusWidget>(this, MenusWidgetClass);
		MenusWidgetInstance->AddToViewport();
		MenusWidgetInstance->TransitionIn();
	}
}

ACorvusPlayerController::ACorvusPlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	PossessedCameras = TArray<ACameraActor*>();
	static ConstructorHelpers::FClassFinder<UObjectViewerWidget> ObjectViewerWidgetClassFinder(TEXT("/Game/UI/ObjectViewer/WBP_ObjectViewer"));
	if (ObjectViewerWidgetClassFinder.Succeeded())
	{
		ObjectViewerWidgetClass = ObjectViewerWidgetClassFinder.Class;
	}

	static ConstructorHelpers::FClassFinder<UMenusWidget> MenusWidgetClassFinder(TEXT("/Game/UI/Menus/WBP_MenusWidget"));
	if (MenusWidgetClassFinder.Succeeded())
	{
		MenusWidgetClass = MenusWidgetClassFinder.Class;
	}
}

void ACorvusPlayerController::OpenObjectViewer(const AInteractable* Interactable)
{
	if (ObjectViewerWidgetClass)
	{
		ObjectViewerWidgetInstance = CreateWidget<UObjectViewerWidget>(this, ObjectViewerWidgetClass);
		ObjectViewerWidgetInstance->InteractableObject = Interactable;
		if (ObjectViewerWidgetInstance)
		{
			ObjectViewerWidgetInstance->AddToViewport();
		}
	}
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
