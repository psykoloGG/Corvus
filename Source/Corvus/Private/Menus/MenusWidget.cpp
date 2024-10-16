#include "Menus/MenusWidget.h"

#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "MediaSource.h"

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

	if (WinScreenImage)
	{
		WinScreenImage->SetVisibility(ESlateVisibility::Hidden);
	}
}

// Transition to main menu
void UMenusWidget::TitleScreenClicked()
{
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::TransitionToMainMenu);
	RebindAnimations();
	TransitionOut();
}

void UMenusWidget::TransitionToMainMenu()
{
	MainMenuOverlay->SetVisibility(ESlateVisibility::Visible);
	TitleScreenImage->SetVisibility(ESlateVisibility::Hidden);
	TransitionIn();
}

// Transition To level selector
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

// For demo just do level 1
void UMenusWidget::LevelButtonClicked()
{
	UnbindAnimationDelegates();
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::TransitionToLevel);
	RebindAnimations();
	TransitionOut();
}

void UMenusWidget::TransitionToLevel()
{
	LevelSelectorOverlay->SetVisibility(ESlateVisibility::Hidden);
	UGameplayStatics::OpenLevel(GetWorld(), "/Game/Levels/Level1/Level1");
	TransitionIn();
}

// For demo purpose just play level 1 win sequence
void UMenusWidget::TriggeredWinScreen()
{
	UE_LOG(LogTemp, Warning, TEXT("Triggered Win Screen"));
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	UnbindAnimationDelegates();
	OnFadeOutFinished.BindDynamic(this, &UMenusWidget::TransitionToWinScreen);
	RebindAnimations();
	TransitionOut();
}

void UMenusWidget::OnMediaOpened(FString OpenedUrl)
{
	TransitionIn();
	WinMediaPlayer->Play();
}

void UMenusWidget::TransitionToWinScreen()
{
	UE_LOG(LogTemp, Warning, TEXT("Transitioning to Win Screen"));
	WinScreenImage->SetVisibility(ESlateVisibility::Visible);
	UMediaSource* MediaSource = LoadObject<UMediaSource>(nullptr, TEXT("/Game/UI/Menus/Graphics/Bench_Scene"));
	WinMediaPlayer->OpenSource(MediaSource);
	WinMediaPlayer->OnMediaOpened.AddDynamic(this, &UMenusWidget::OnMediaOpened);
}

void UMenusWidget::TransitionIn()
{
	PlayAnimation(FadeInAnimation);
}

void UMenusWidget::TransitionOut()
{
	UE_LOG(LogTemp, Warning, TEXT("Transitioning Out"));
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
