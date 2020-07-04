// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "MyProject2GameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuHUD.h"
#include "LabyBotPlayerController.h"

AMyProject2GameModeBase::AMyProject2GameModeBase() 
{
	PlayerControllerClass = ALabyBotPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}