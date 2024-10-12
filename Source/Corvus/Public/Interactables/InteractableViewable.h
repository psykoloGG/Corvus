#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "InteractableViewable.generated.h"

/**
 * Interactable which when clicked on can be viewed in the object viewer
 */
UCLASS()
class CORVUS_API AInteractableViewable : public AInteractable
{
	GENERATED_BODY()

public:
	AInteractableViewable();
	
	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed) override;
	
};
