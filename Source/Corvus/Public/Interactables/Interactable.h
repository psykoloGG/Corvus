#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

/**
 * Base class for creating interactable map objects
 */
UCLASS(Abstract)
class CORVUS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractable();

	UFUNCTION()
	virtual void OnInteracted(AActor* TouchedActor, FKey ButtonPressed);
	
	// Item name used for list of objectives
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	FString Description;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interactable")
	UStaticMeshComponent* StaticMeshComponent;

};
