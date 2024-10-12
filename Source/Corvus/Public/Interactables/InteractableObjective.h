#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "InteractableObjective.generated.h"

/**
 * Interactable object that would mark of an objective or win the game if clicked
 */
UCLASS()
class CORVUS_API AInteractableObjective : public AInteractable
{
	GENERATED_BODY()
public:
	AInteractableObjective();
	
	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed) override;
};
