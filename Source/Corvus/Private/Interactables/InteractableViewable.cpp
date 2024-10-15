#include "Interactables/InteractableViewable.h"

#include "CorvusGameInstance.h"
#include "CorvusPlayerController.h"
#include "Kismet/GameplayStatics.h"

AInteractableViewable::AInteractableViewable()
{
	
}

void AInteractableViewable::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
	UCorvusGameInstance* GameInstance = Cast<UCorvusGameInstance>(GetGameInstance());
	if (GameInstance)
	{
		GameInstance->OpenObjectViewer(this);
	}
}
