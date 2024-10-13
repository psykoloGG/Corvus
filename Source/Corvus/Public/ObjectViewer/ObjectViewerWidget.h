#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectViewerWidget.generated.h"

class AInteractable;
/**
 * 
 */
UCLASS()
class CORVUS_API UObjectViewerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

private:
	UPROPERTY()
	bool bMouseDown = false;

	UPROPERTY()
	FVector2D PreviousMousePosition;

	UPROPERTY()
	class AViewableObject* ViewableObj;

	UPROPERTY()
	float SizeFactor = 1.0f;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	const AInteractable* InteractableObject;
};
