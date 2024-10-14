#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenusWidget.generated.h"

/**
 * Widget for all menus, transitions and other UI stuff
 */
UCLASS()
class CORVUS_API UMenusWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	
public:
	
};
