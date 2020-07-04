// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEndTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "MainCameraPawn.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

ALevelEndTriggerBox::ALevelEndTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ALevelEndTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALevelEndTriggerBox::OnOverlapEnd);
	//JokerMesh->SetupAttachment()
	
}

void ALevelEndTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1,0,5);
}

void ALevelEndTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		AMainCameraPawn* MainCameraPawnPointer = Cast<AMainCameraPawn>(MainCameraPawn);
		FString filename = "BestScore.txt";
		FString fromInt = FString::FromInt(MainCameraPawnPointer->UITimer);
		if (MainCameraPawnPointer->BestScore > MainCameraPawnPointer->UITimer) {
			FFileHelper::SaveStringToFile(fromInt, *(FPaths::ProjectDir() + filename));
		}
		UGameplayStatics::OpenLevel(GetWorld(), "LabyBotTestMap");
		//print("Overlap Begins");
		//printf("Overlapped Actor = %s", *OverlappedActor->GetName());
		
	}
}

void ALevelEndTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		//print("Overlap Ends");
		//printf("Overlapped Actor = %s", *OtherActor->GetName());
	}
}