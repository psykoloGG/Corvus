#include "Interactables/InteractableObjective.h"

#include "CorvusGameInstance.h"

AInteractableObjective::AInteractableObjective()
{
	
}

void AInteractableObjective::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
	UCorvusGameInstance* GameInstance = Cast<UCorvusGameInstance>(GetGameInstance());
	GameInstance->TriggerLevelWin();
}
