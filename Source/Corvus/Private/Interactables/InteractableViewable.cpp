#include "Interactables/InteractableViewable.h"

#include "CorvusPlayerController.h"
#include "Kismet/GameplayStatics.h"

AInteractableViewable::AInteractableViewable()
{
	
}

void AInteractableViewable::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
	StaticCast<ACorvusPlayerController*>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->OpenObjectViewer(this);
}
