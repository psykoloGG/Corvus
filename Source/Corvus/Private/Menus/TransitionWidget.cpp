#include "Menus/TransitionWidget.h"

void UTransitionWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UTransitionWidget::FadeIn()
{
	PlayAnimation(FadeInAnimation);
}

void UTransitionWidget::FadeOut()
{
	PlayAnimation(FadeOutAnimation);
}
