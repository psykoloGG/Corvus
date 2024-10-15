#include "Menus/MenusWidget.h"

#include "Components/Image.h"

void UMenusWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (TransitionImage)
	{
		TransitionImage->SetVisibility(ESlateVisibility::HitTestInvisible);
	}

	if (MainMenuOverlay)
	{
		MainMenuOverlay->SetVisibility(ESlateVisibility::Hidden);
	}

	if (LevelSelectorOverlay)
	{
		LevelSelectorOverlay->SetVisibility(ESlateVisibility::Hidden);
	}
}

// Triggers transition to main menu
void UMenusWidget::TitleScreenClicked()
{
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::TransitionToMainMenu);
	RebindAnimations();
	TransitionOut();
}

// Transitioned to main menu
void UMenusWidget::TransitionToMainMenu()
{
	MainMenuOverlay->SetVisibility(ESlateVisibility::Visible);
	TitleScreenImage->SetVisibility(ESlateVisibility::Hidden);
	TransitionIn();
}

void UMenusWidget::MainMenuPlayButtonClicked()
{
	UnbindAnimationDelegates();
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::TransitionToLevelSelector);
	RebindAnimations();
	TransitionOut();
}

void UMenusWidget::TransitionToLevelSelector()
{
	MainMenuOverlay->SetVisibility(ESlateVisibility::Hidden);
	LevelSelectorOverlay->SetVisibility(ESlateVisibility::Visible);
	TransitionIn();
}


void UMenusWidget::TransitionIn()
{
	PlayAnimation(FadeInAnimation);
}

void UMenusWidget::TransitionOut()
{
	PlayAnimation(FadeOutAnimation);
}

void UMenusWidget::RebindAnimations()
{
	UnbindAllFromAnimationFinished(FadeInAnimation);
	UnbindAllFromAnimationFinished(FadeOutAnimation);
	
	if (FadeInAnimation)
	{
		BindToAnimationFinished(FadeInAnimation, OnFadeInFinished);
	}

	if (FadeOutAnimation)
	{
		BindToAnimationFinished(FadeOutAnimation, OnFadeOutFinished);
	}
}

void UMenusWidget::UnbindAnimationDelegates()
{
	OnFadeOutFinished.Unbind();
	OnFadeInFinished.Unbind();
}
