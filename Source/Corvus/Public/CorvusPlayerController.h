#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "GameFramework/PlayerController.h"
#include "CorvusPlayerController.generated.h"

/**
 * Class controls camera behavior, mouse moves and clicks
 */
UCLASS()
class CORVUS_API ACorvusPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
public:
	ACorvusPlayerController();

	UFUNCTION()
	void OpenObjectViewer(const AInteractable* Interactable);

	// Called when map gets loaded (aka begin play for level)
	UFUNCTION(BlueprintCallable)
	void SetupForLevel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class ACameraActor*> PossessedCameras;

	// Raycasting for highlighting objects
	UPROPERTY()
	bool bShouldRaycast = false;

	UFUNCTION()
	void TransitionIn();

	UFUNCTION()
	void TransitionOut();

private:
	UPROPERTY()
	TSubclassOf<UUserWidget> ObjectViewerWidgetClass;

	UPROPERTY()
	TSubclassOf<UUserWidget> TitleScreenClass;

	UPROPERTY()
	TSubclassOf<UUserWidget> TransitionWidgetClass;
	
	UPROPERTY()
	class UObjectViewerWidget* ObjectViewerWidgetInstance = nullptr;

	UPROPERTY()
	class UTitleScreenWidget* TitleScreenWidgetInstance = nullptr;

	UPROPERTY()
	class UTransitionWidget* TransitionWidgetInstance = nullptr;
};
