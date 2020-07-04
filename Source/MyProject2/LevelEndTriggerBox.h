// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LevelEndTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ALevelEndTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	ALevelEndTriggerBox();
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UPROPERTY(EditAnywhere)
		AActor* MainCameraPawn;
};
