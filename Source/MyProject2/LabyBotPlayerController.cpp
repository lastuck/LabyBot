// Fill out your copyright notice in the Description page of Project Settings.


#include "LabyBotPlayerController.h"
#include "MenuHUD.h"

ALabyBotPlayerController::ALabyBotPlayerController() {

}

void ALabyBotPlayerController::SetupInputComponent() {

}

void ALabyBotPlayerController::OpenMenu() {
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD())) {
		MenuHUD->ShowMenu();
	}
}