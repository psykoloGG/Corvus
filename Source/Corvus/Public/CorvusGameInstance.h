#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CorvusGameInstance.generated.h"

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
	void TriggerLevelWin();
	
protected:
	virtual void Init() override;
	
private:
	UPROPERTY()
	TSubclassOf<UUserWidget> ObjectViewerWidgetClass;
	
	UPROPERTY()
	class UObjectViewerWidget* ObjectViewerWidgetInstance = nullptr;

	UPROPERTY()
	TSubclassOf<UUserWidget> MenusWidgetClass;

	UPROPERTY()
	class UMenusWidget* MenusWidgetInstance = nullptr;

	// Use to determine if we need to initialize menu on begin play
	bool bMenuInitialized = false;
	
};
