// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainCameraPawn.generated.h"

UCLASS()
class MYPROJECT2_API AMainCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	FHitResult* HitResult;

	UPROPERTY(EditAnyWhere)
		AActor* mainCamera;
	UPROPERTY(EditAnyWhere)
		AActor* JokerPreviewObject;
	UPROPERTY(EditAnyWhere)
		AActor* Joker1;
	UPROPERTY(EditAnyWhere)
		AActor* Joker2;
	UPROPERTY(EditAnyWhere)
		AActor* Joker3;
	
	int SelectedJoker;
	bool TurnRight;

	UFUNCTION()
		void SelectJoker1();
	UFUNCTION()
		void SelectJoker2();
	UFUNCTION()
		void SelectJoker3();
	UFUNCTION()
		void SpawnJoker();
	UFUNCTION()
		void ChangeJokerRotation();
};
