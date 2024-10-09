#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CorvusGameMode.generated.h"

/**
 * Custom GameMode for setting default code defined classes (like APlayerPawn)
 */
UCLASS()
class CORVUS_API ACorvusGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACorvusGameMode();
};
