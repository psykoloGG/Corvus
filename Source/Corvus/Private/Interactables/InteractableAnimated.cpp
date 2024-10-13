#include "Interactables/InteractableAnimated.h"

#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"

AInteractableAnimated::AInteractableAnimated()
{
	
}

void AInteractableAnimated::OnInteracted(AActor* TouchedActor, FKey ButtonPressed)
{
	if (bInteracted)
	{
		return;
	}
	
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
