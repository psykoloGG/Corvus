#include "CorvusGameInstance.h"

#include "Blueprint/UserWidget.h"
#include "Menus/MenusWidget.h"
#include "ObjectViewer/ObjectViewerWidget.h"

UCorvusGameInstance::UCorvusGameInstance()
{
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

void UCorvusGameInstance::OpenObjectViewer(const AInteractable* Interactable)
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

void UCorvusGameInstance::TriggerLevelWin()
{
	if (MenusWidgetInstance)
	{
		MenusWidgetInstance->TriggeredWinScreen();
	}
}

void UCorvusGameInstance::Init()
{
	Super::Init();

	UGameViewportClient::OnViewportCreated().AddLambda([this]()
	{
		if (!MenusWidgetInstance && MenusWidgetClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("No menus widget instance found, creating one"));
			MenusWidgetInstance = CreateWidget<UMenusWidget>(this, MenusWidgetClass);
			MenusWidgetInstance->AddToViewport();
			MenusWidgetInstance->TransitionIn();
		}	
	});
}
