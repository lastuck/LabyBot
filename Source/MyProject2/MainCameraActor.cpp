// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AMainCameraActor::AMainCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//InputComponent->BindAction("LeftMouse", IE_Pressed, this, AMainCameraActor::SpawnJoker());
}

// Called when the game starts or when spawned
void AMainCameraActor::BeginPlay()
{
	Super::BeginPlay();
	//APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);
	//OurPlayer->SetViewTarget(mainCamera);
}

// Called every frame
void AMainCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*FVector mouseLocation, mouseDirection;
	APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayer->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

	FHitResult* HitResult = new FHitResult();
	FVector StartTrace;
	StartTrace.X = -130.f;
	StartTrace.Y = 590.f;
	StartTrace.Z = 8900.f;
	FVector ForwardVector = mouseDirection*10.f;
	FVector EndTrace = ((ForwardVector *5000.f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

	if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams)) {
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
		JokerObject->SetActorLocation(HitResult->Location);
	}*/
}

void AMainCameraActor::SpawnJoker() {
	JokerObject->Destroy();
}
