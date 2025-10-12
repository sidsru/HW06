
#include "SpartaPlayerController.h"
#include "EnhancedInputSubsystems.h"

ASpartaPlayerController::ASpartaPlayerController()
	: IMC(nullptr),
	  MoveAction(nullptr),
	  LookAction(nullptr),
	  SprintAction(nullptr),
	  JumpAction(nullptr)
{
}

void ASpartaPlayerController::BeginPlay()
{
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (IMC)
			{
				SubSystem->AddMappingContext(IMC, 0);
			}
		}
	}
}
