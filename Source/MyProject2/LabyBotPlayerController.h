// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LabyBotPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ALabyBotPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	ALabyBotPlayerController();
	virtual void SetupInputComponent() override;
	void OpenMenu();
};
