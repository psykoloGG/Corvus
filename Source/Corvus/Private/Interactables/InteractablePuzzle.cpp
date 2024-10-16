#include "Interactables/InteractablePuzzle.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"

AInteractablePuzzle::AInteractablePuzzle()
{
	
}

void AInteractablePuzzle::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
	if (bInteracted)
	{
		return;
	}
	UCorvusGameInstance* GameInstance = Cast<UCorvusGameInstance>(GetGameInstance());
	if (GameInstance)
	{
		GameInstance->OpenPuzzleViewer(EPuzzleType::EnterCode, this);
	}
}

void AInteractablePuzzle::PuzzleSolved()
{
	ALevelSequenceActor* LevelSequenceActor;
	FMovieSceneSequencePlaybackSettings Settings;
	Settings.bAutoPlay = false;
	Settings.bPauseAtEnd = true;

	ULevelSequencePlayer* SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), AnimationSequence, Settings, LevelSequenceActor);
	if (SequencePlayer)
	{
		SequencePlayer->Play();
	}
	bInteracted = true;
}
