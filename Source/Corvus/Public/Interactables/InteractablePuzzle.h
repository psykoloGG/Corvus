#pragma once

#include "CoreMinimal.h"
#include "CorvusGameInstance.h"
#include "Interactables/Interactable.h"
#include "InteractablePuzzle.generated.h"

class ULevelSequence;
/**
 * Object that opens up a puzzle when clicked on (like a code input)
 */
UCLASS()
class CORVUS_API AInteractablePuzzle : public AInteractable
{
	GENERATED_BODY()

public:
	AInteractablePuzzle();

	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed) override;

	UFUNCTION(BlueprintCallable)
	void PuzzleSolved();

	UPROPERTY(EditAnywhere, Category = "Puzzle")
	EPuzzleType PuzzleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PuzzleAnswer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ULevelSequence* AnimationSequence;

private:
	bool bInteracted = false;
};
