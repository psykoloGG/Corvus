#include "CorvusGameInstance.h"

#include "CodePuzzleWidget.h"
#include "Blueprint/UserWidget.h"
#include "Interactables/InteractablePuzzle.h"
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

	static ConstructorHelpers::FClassFinder<UCodePuzzleWidget> CodePuzzleWidgetClassFinder(TEXT("/Game/UI/Puzzles/WBP_CodePuzzle"));
	if (CodePuzzleWidgetClassFinder.Succeeded())
	{
		CodePuzzleWidgetClass = CodePuzzleWidgetClassFinder.Class;
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

void UCorvusGameInstance::OpenPuzzleViewer(const EPuzzleType PuzzleType, AInteractablePuzzle* Interactable)
{
	if (CodePuzzleWidgetClass)
	{
		CodePuzzleWidgetInstance = CreateWidget<UCodePuzzleWidget>(this, CodePuzzleWidgetClass);
		CodePuzzleWidgetInstance->InteractablePuzzle = Interactable;
		if (CodePuzzleWidgetInstance)
		{
			CodePuzzleWidgetInstance->AddToViewport();
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

void UCorvusGameInstance::InitMainUI()
{
	if (!MenusWidgetInstance && MenusWidgetClass)
	{
		MenusWidgetInstance = CreateWidget<UMenusWidget>(this, MenusWidgetClass);
		MenusWidgetInstance->AddToViewport();
		MenusWidgetInstance->TransitionIn();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Menu widget creating"));
	}	
}
