// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "JokerTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API AJokerTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AJokerTriggerBox();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void PutMeshHere();

	UFUNCTION()
	void ChangeRotation(bool wantedRotation);

	UPROPERTY(EditAnywhere)
	AActor* JokerMesh;
	UPROPERTY(EditAnywhere)
	bool TurnRight;
};
