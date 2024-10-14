#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TransitionWidget.generated.h"

/**
 * Widget used for transitioning between menus.
 */
UCLASS()
class CORVUS_API UTransitionWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void FadeIn();

	UFUNCTION(BlueprintCallable)
	void FadeOut();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeInAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetAnimation* FadeOutAnimation;
};
