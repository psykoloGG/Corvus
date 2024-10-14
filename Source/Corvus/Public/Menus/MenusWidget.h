#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenusWidget.generated.h"

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
	UFUNCTION()
	void TransitionToMainMenu();

	UFUNCTION()
	void TransitionToGame();
	
	UFUNCTION()
	void TransitionIn();

	UFUNCTION()
	void TransitionOut();

	UFUNCTION()
	void FadeInFinished();

	UFUNCTION()
	void FadeOutFinished();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeInAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeOutAnimation;

	FWidgetAnimationDynamicEvent OnFadeInFinished;
	FWidgetAnimationDynamicEvent OnFadeOutFinished;

private:
	
};
