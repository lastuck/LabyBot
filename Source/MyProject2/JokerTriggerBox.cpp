// Fill out your copyright notice in the Description page of Project Settings.

#include "JokerTriggerBox.h"
#include "DrawDebugHelpers.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,0.5,FColor::Green, text)
#define printf(text,fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,0.5,FColor::Green, FString::Printf(TEXT(text), fstring))



AJokerTriggerBox::AJokerTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AJokerTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AJokerTriggerBox::OnOverlapEnd);
	//JokerMesh->SetupAttachment()
	TurnRight = true;
}

void AJokerTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	//DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1,0,5);
}

void AJokerTriggerBox::PutMeshHere()
{
	JokerMesh->SetActorLocation(this->GetActorLocation()+this->GetActorUpVector()*100.f);
}

void AJokerTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		//print("Overlap Begins");
		//printf("Overlapped Actor = %s", *OverlappedActor->GetName());
		FRotator NewRotation;
		if (TurnRight) {
			NewRotation = FRotator(0.f, 90.f, 0.f);
		}
		else {
			NewRotation = FRotator(0.f, -90.f, 0.f);
		}
		FQuat QuatRotation = FQuat(NewRotation);
		OtherActor->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	}
}
void AJokerTriggerBox::ChangeRotation(bool wantedRotation) {
	TurnRight = wantedRotation;
}
void AJokerTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		//print("Overlap Ends");
		//printf("Overlapped Actor = %s", *OtherActor->GetName());
	}
}
