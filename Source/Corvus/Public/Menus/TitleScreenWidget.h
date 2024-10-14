#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleScreenWidget.generated.h"

/**
 * Widget for title screen and its behavior.
 */
UCLASS()
class CORVUS_API UTitleScreenWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
public:
	UFUNCTION(BlueprintCallable)
	void StartGame();
};
