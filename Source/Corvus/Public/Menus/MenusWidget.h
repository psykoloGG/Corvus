#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Overlay.h"
#include "Runtime/MediaAssets/Public/MediaPlayer.h"
#include "MenusWidget.generated.h"

class UImage;
/**
 * Widget for all menus, transitions and other UI stuff
 */
UCLASS()
class CORVUS_API UMenusWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void MainMenuPlayButtonClicked();

	UFUNCTION(BlueprintCallable)
	void TitleScreenClicked();

	// For demo purposes default to level 1  
	UFUNCTION(BlueprintCallable)
	void LevelButtonClicked();


	UFUNCTION()
	void TransitionToMainMenu();

	UFUNCTION()
	void TransitionToLevelSelector();

	UFUNCTION()
	void TransitionToLevel();

	UFUNCTION()
	void TriggeredWinScreen();

	UFUNCTION()
	void OnMediaOpened(FString OpenedUrl);
	
	UFUNCTION()
	void TransitionToWinScreen();

	
	// Transitions
	UFUNCTION()
	void TransitionIn();

	UFUNCTION()
	void TransitionOut();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeInAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeOutAnimation;

	FWidgetAnimationDynamicEvent OnFadeInFinished;
	FWidgetAnimationDynamicEvent OnFadeOutFinished;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* TitleScreenImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* TransitionImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UOverlay* MainMenuOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UOverlay* LevelSelectorOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* WinScreenImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMediaPlayer* WinMediaPlayer;

private:
	void RebindAnimations();

	void UnbindAnimationDelegates();
};
