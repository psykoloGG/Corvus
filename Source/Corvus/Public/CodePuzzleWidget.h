#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CodePuzzleWidget.generated.h"

class AInteractablePuzzle;
/**
 * Code input puzzle widget
 * Lord help me this blueprint is ugly (to be fixed :) )
 */
UCLASS()
class CORVUS_API UCodePuzzleWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(BlueprintReadOnly)
	FString AnswerCode;

	UPROPERTY(BlueprintReadWrite)
	AInteractablePuzzle* InteractablePuzzle;
};
