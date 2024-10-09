#include "Interactable.h"

#include "CorvusPlayerController.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AInteractable::AInteractable()
{
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = StaticMesh;

    OnClicked.AddDynamic(this, &AInteractable::OnInteracted);
}

void AInteractable::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
    UE_LOG(LogTemp, Warning, TEXT("Interacted with %s"), *GetName());
    StaticCast<ACorvusPlayerController*>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->OpenObjectViewer(this);
}

