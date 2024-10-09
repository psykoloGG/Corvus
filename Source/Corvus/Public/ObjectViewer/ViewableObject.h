#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "ViewableObject.generated.h"

UCLASS()
class CORVUS_API AViewableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AViewableObject();

	void RotateSpringArm(float DeltaYaw, float DeltaPitch);
	void ZoomInObject(float DeltaZoom);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ObjectMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneCaptureComponent2D* SceneCapture;
};
