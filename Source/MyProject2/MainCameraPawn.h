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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		int RemainingBattery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool StartGame;
	UPROPERTY(EditAnywhere)
		AActor* labybot;
	UPROPERTY(EditAnywhere)
		AActor* Alarm1;
	UPROPERTY(EditAnywhere)
		AActor* Alarm2;
	UPROPERTY(EditAnywhere)
		AActor* Alarm3;

	int SelectedJoker;
	bool TurnRight;
	FTimerHandle MemberTimerHandle;
	FTimerHandle MemberTimerHandle2;
	bool LightsOff;
	int UITimer;
	int BestScore;

	UFUNCTION(BlueprintCallable, Category = "My Functions")
		void SelectJoker1();
	UFUNCTION()
		void SelectJoker2();
	UFUNCTION()
		void SelectJoker3();
	UFUNCTION()
		void SpawnJoker();
	UFUNCTION()
		void ChangeJokerRotation();

	UFUNCTION()
		void DecreaseBattery();

	UFUNCTION()
		void IncreaseTimer();

	UFUNCTION()
		void StartRobot();

	UFUNCTION()
		void ShowBestTime();
};
