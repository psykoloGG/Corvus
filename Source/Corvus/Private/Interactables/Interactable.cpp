#include "Interactables/Interactable.h"

AInteractable::AInteractable()
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = StaticMeshComponent;

    OnClicked.AddDynamic(this, &AInteractable::OnInteracted);
}

void AInteractable::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
    
}

