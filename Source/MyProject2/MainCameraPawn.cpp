// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCameraPawn.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "JokerTriggerBox.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green, text)

// Sets default values
AMainCameraPawn::AMainCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayer->SetViewTarget(mainCamera);
	SelectedJoker = 0;
	TurnRight = true;
}

// Called every frame
void AMainCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector mouseLocation, mouseDirection;
	APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayer->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

	HitResult = new FHitResult();
	FVector StartTrace;
	StartTrace.X = -130.f;
	StartTrace.Y = 590.f;
	StartTrace.Z = 8900.f;
	FVector ForwardVector = mouseDirection * 10.f;
	FVector EndTrace = ((ForwardVector *5000.f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams)) {
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
		JokerPreviewObject->SetActorLocation(HitResult->Location);
		//print("yay");
	}
}

void AMainCameraPawn::SpawnJoker() {
	//JokerPreviewObject->Destroy();
	if (SelectedJoker == 0) {
		Joker1->SetActorLocation(HitResult->Location);
		AJokerTriggerBox* Joker1Pointer = Cast<AJokerTriggerBox>(Joker1);
		Joker1Pointer->PutMeshHere();
		Joker1Pointer->ChangeRotation(TurnRight);
	}
	else if (SelectedJoker == 1) {
		Joker2->SetActorLocation(HitResult->Location);
		AJokerTriggerBox* Joker2Pointer = Cast<AJokerTriggerBox>(Joker2);
		Joker2Pointer->PutMeshHere();
		Joker2Pointer->ChangeRotation(TurnRight);
	}
	else if (SelectedJoker == 2) {
		Joker3->SetActorLocation(HitResult->Location);
		AJokerTriggerBox* Joker3Pointer = Cast<AJokerTriggerBox>(Joker3);
		Joker3Pointer->PutMeshHere();
		Joker3Pointer->ChangeRotation(TurnRight);
	}
	//print("yay");
}

void AMainCameraPawn::SelectJoker1() {
	SelectedJoker = 0;
}
void AMainCameraPawn::SelectJoker2() {
	SelectedJoker = 1;
}
void AMainCameraPawn::SelectJoker3() {
	SelectedJoker = 2;
}

void AMainCameraPawn::ChangeJokerRotation() {
	TurnRight = !TurnRight;
}
// Called to bind functionality to input
void AMainCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, this, &AMainCameraPawn::SpawnJoker);
	PlayerInputComponent->BindAction("Input1", IE_Pressed, this, &AMainCameraPawn::SelectJoker1);
	PlayerInputComponent->BindAction("Input2", IE_Pressed, this, &AMainCameraPawn::SelectJoker2);
	PlayerInputComponent->BindAction("Input3", IE_Pressed, this, &AMainCameraPawn::SelectJoker3);
	PlayerInputComponent->BindAction("ScrollUp", IE_Pressed, this, &AMainCameraPawn::ChangeJokerRotation);
	PlayerInputComponent->BindAction("ScrollDown", IE_Pressed, this, &AMainCameraPawn::ChangeJokerRotation);
}

