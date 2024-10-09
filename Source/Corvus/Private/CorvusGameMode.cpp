#include "CorvusGameMode.h"

#include "CorvusPlayerController.h"
#include "PlayerPawn.h"

ACorvusGameMode::ACorvusGameMode()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = ACorvusPlayerController::StaticClass();
}
