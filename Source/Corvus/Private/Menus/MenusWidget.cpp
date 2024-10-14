#include "Menus/MenusWidget.h"

void UMenusWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (FadeInAnimation)
	{
		BindToAnimationFinished(FadeInAnimation, OnFadeInFinished);
	}

	if (FadeOutAnimation)
	{
		BindToAnimationFinished(FadeOutAnimation, OnFadeOutFinished);
	}

	OnFadeInFinished.BindDynamic(this, &UMenusWidget::FadeInFinished);
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::FadeOutFinished);
}

void UMenusWidget::TransitionToMainMenu()
{
	
}

void UMenusWidget::TransitionToGame()
{
}

void UMenusWidget::TransitionIn()
{
	PlayAnimation(FadeInAnimation);
}

void UMenusWidget::TransitionOut()
{
	PlayAnimation(FadeOutAnimation);
}

void UMenusWidget::FadeInFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Fade in finished"));
}

void UMenusWidget::FadeOutFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Fade out finished"));
}
