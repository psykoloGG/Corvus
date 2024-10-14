#include "CorvusPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Menus/TitleScreenWidget.h"
#include "Menus/TransitionWidget.h"
#include "ObjectViewer/ObjectViewerWidget.h"

void ACorvusPlayerController::BeginPlay()
{
	Super::BeginPlay();

	TitleScreenWidgetInstance = CreateWidget<UTitleScreenWidget>(this, TitleScreenClass);
	if (TitleScreenWidgetInstance)
	{
		TitleScreenWidgetInstance->AddToViewport();
	}
	
	TransitionWidgetInstance = CreateWidget<UTransitionWidget>(this, TransitionWidgetClass);
	if (TransitionWidgetInstance)
	{
		TransitionWidgetInstance->AddToViewport();
	}

	// Hardcode timings for demo
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
	   {
			TransitionOut();

	   }, 2.0f, false);
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

	static ConstructorHelpers::FClassFinder<UTitleScreenWidget> TitleScreenWidgetClassFinder(TEXT("/Game/UI/Menus/WBP_TitleScreen"));
	if (TitleScreenWidgetClassFinder.Succeeded())
	{
		TitleScreenClass = TitleScreenWidgetClassFinder.Class;
	}

	static ConstructorHelpers::FClassFinder<UTransitionWidget> TransitionWidgetClassFinder(TEXT("/Game/UI/Menus/WBP_Transition"));
	if (TransitionWidgetClassFinder.Succeeded())
	{
		TransitionWidgetClass = TransitionWidgetClassFinder.Class;
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

void ACorvusPlayerController::TransitionIn()
{
	TransitionWidgetInstance->FadeIn();
}

void ACorvusPlayerController::TransitionOut()
{
	TransitionWidgetInstance->FadeOut();
}
