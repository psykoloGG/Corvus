#include "Menus/TitleScreenWidget.h"

#include "CorvusPlayerController.h"
#include "Kismet/GameplayStatics.h"

FReply UTitleScreenWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	StartGame();
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UTitleScreenWidget::StartGame()
{
	CastChecked<ACorvusPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->TransitionIn();
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
   {
		RemoveFromParent();
		CastChecked<ACorvusPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->TransitionOut();
   }, 1.0f, false);
}
