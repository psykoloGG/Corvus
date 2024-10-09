#include "ObjectViewer/ObjectViewerWidget.h"

#include "ObjectViewer/ViewableObject.h"

void UObjectViewerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ViewableObj = GetWorld()->SpawnActor<AViewableObject>(AViewableObject::StaticClass());
	ViewableObj->SetActorLocation(FVector(0.0f, 0.0f, -10000.0f));
	ViewableObj->ObjectMesh->SetStaticMesh(ObjectMesh);

	float Size = ViewableObj->ObjectMesh->GetStaticMesh()->GetBoundingBox().GetSize().Size();
	ViewableObj->SpringArm->TargetArmLength = Size * 1.5f;
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
		UE_LOG(LogTemp , Warning, TEXT("Mouse moved"));
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
	ViewableObj->ZoomInObject(-WheelDelta);
	return FReply::Handled();
}
