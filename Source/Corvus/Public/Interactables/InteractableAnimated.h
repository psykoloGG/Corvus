#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "InteractableAnimated.generated.h"

/**
 * Object plays animation (drawers open) when clicked on
 */
UCLASS()
class CORVUS_API AInteractableAnimated : public AInteractable
{
	GENERATED_BODY()

public:
	AInteractableAnimated();

	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimationAsset* Animation;
};
