#include "ObjectViewer/ViewableObject.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"

AViewableObject::AViewableObject()
{
	ObjectMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = ObjectMeshComponent;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(ObjectMeshComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CameraComponent"));
	SceneCapture->SetupAttachment(SpringArm);
	// Make this dependent on the mesh size
	SceneCapture->ShowOnlyComponent(ObjectMeshComponent);
	SceneCapture->CustomNearClippingPlane = 0.0001f;
	SceneCapture->bOverride_CustomNearClippingPlane = true;
	
	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> TextureRenderTargetObject(TEXT("/Script/Engine.TextureRenderTarget2D'/Game/UI/ObjectViewer/RT_ObjectViewer.RT_ObjectViewer'"));
	if (TextureRenderTargetObject.Succeeded())
	{
		SceneCapture->TextureTarget = TextureRenderTargetObject.Object;
	}
}

void AViewableObject::RotateSpringArm(float DeltaYaw, float DeltaPitch)
{
	SpringArm->AddLocalRotation(FRotator(DeltaPitch, DeltaYaw, 0.0f));
}

void AViewableObject::ZoomInObject(float DeltaZoom)
{
	SpringArm->TargetArmLength += DeltaZoom;
}

