#include "ObjectViewer/ObjectViewerWidget.h"

#include "Interactables/Interactable.h"
#include "ObjectViewer/ViewableObject.h"

void UObjectViewerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ViewableObj = GetWorld()->SpawnActor<AViewableObject>(AViewableObject::StaticClass());
	ViewableObj->SetActorLocation(FVector(0.0f, 0.0f, -10000.0f));
	ViewableObj->ObjectMeshComponent->SetStaticMesh(InteractableObject->StaticMeshComponent->GetStaticMesh());
	ViewableObj->ObjectMeshComponent->SetRelativeScale3D(InteractableObject->StaticMeshComponent->GetRelativeScale3D());

	SizeFactor = InteractableObject->GetComponentsBoundingBox().GetExtent().GetMax();
	ViewableObj->SpringArm->TargetArmLength = SizeFactor * 2;
}

FReply UObjectViewerWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	bMouseDown = true;
	PreviousMousePosition = InMouseEvent.GetScreenSpacePosition();
	return FReply::Handled();
}

FReply UObjectViewerWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	bMouseDown = false;
	return FReply::Handled();
}

FReply UObjectViewerWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (bMouseDown)
	{
		FVector2D CurrentMousePosition = InMouseEvent.GetScreenSpacePosition();
		FVector2D Delta = CurrentMousePosition - PreviousMousePosition;
		ViewableObj->RotateSpringArm(Delta.X, -Delta.Y);
		PreviousMousePosition = CurrentMousePosition;
	}
	return FReply::Handled();
}

FReply UObjectViewerWidget::NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	float WheelDelta = InMouseEvent.GetWheelDelta();
	ViewableObj->ZoomInObject(-WheelDelta * (SizeFactor / 10));
	return FReply::Handled();
}
