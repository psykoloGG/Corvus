#include "CodePuzzleWidget.h"

#include "Interactables/InteractablePuzzle.h"

void UCodePuzzleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AnswerCode = InteractablePuzzle->PuzzleAnswer;
}
