#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CorvusGameInstance.generated.h"

class AInteractablePuzzle;

UENUM()
enum class EPuzzleType
{
    EnterCode,
	UseItem
};

class AInteractable;
/**
 * 
 */
UCLASS()
class CORVUS_API UCorvusGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCorvusGameInstance();
	
	UFUNCTION()
	void OpenObjectViewer(const AInteractable* Interactable);
	
	UFUNCTION()
	void OpenPuzzleViewer(const EPuzzleType PuzzleType, AInteractablePuzzle* Interactable);

	UFUNCTION()
	void TriggerLevelWin();
	
protected:
	virtual void Init() override;
	
private:
	UPROPERTY()
	TSubclassOf<UUserWidget> ObjectViewerWidgetClass;
	
	UPROPERTY()
	class UObjectViewerWidget* ObjectViewerWidgetInstance = nullptr;

	// Need a way to streamline puzzles and then differentiate within (for demo leave as is)
	UPROPERTY()
	TSubclassOf<UUserWidget> CodePuzzleWidgetClass;

	UPROPERTY()
	class UCodePuzzleWidget* CodePuzzleWidgetInstance = nullptr;

	UPROPERTY()
	TSubclassOf<UUserWidget> MenusWidgetClass;

	UPROPERTY()
	class UMenusWidget* MenusWidgetInstance = nullptr;

	// Use to determine if we need to initialize menu on begin play
	bool bMenuInitialized = false;
	
};
