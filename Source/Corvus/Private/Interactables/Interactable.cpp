#include "Interactables/Interactable.h"

AInteractable::AInteractable()
{
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = StaticMesh;

    OnClicked.AddDynamic(this, &AInteractable::OnInteracted);
}

void AInteractable::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
    
}

