#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "InteractablePickup.generated.h"

/**
 * Object gets put into inventory when clicked on
 */
UCLASS()
class CORVUS_API AInteractablePickup : public AInteractable
{
	GENERATED_BODY()
public:
	AInteractablePickup();
	
	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed) override;
};
