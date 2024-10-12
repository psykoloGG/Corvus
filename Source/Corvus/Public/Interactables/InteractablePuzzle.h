

#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "InteractablePuzzle.generated.h"

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
	
};
