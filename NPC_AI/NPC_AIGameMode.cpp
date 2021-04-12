// Copyright Epic Games, Inc. All Rights Reserved.

#include "NPC_AIGameMode.h"
#include "NPC_AICharacter.h"
#include "UObject/ConstructorHelpers.h"

ANPC_AIGameMode::ANPC_AIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
