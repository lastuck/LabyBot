// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LabyBotPawn.generated.h"

UCLASS()
class MYPROJECT2_API ALabyBotPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALabyBotPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	void MoveForwardAxis(float value);
	void StartMovingForward();
	void StopMovingForward();

	FVector CurrentVelocity;
	FVector CurrentLocation;
	bool bMoving;
};
