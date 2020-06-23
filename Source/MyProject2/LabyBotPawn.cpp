// Fill out your copyright notice in the Description page of Project Settings.


#include "LabyBotPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine.h"
#include "DrawDebugHelpers.h"


// Sets default values
ALabyBotPawn::ALabyBotPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);
	CurrentLocation = this->GetActorLocation();

}

// Called when the game starts or when spawned
void ALabyBotPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALabyBotPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		CurrentLocation += GetActorForwardVector() * 200.0f * DeltaTime;

		SetActorLocation(CurrentLocation);
		
		FHitResult* HitResult = new FHitResult();
		FVector StartTrace = this->GetActorLocation();
		FVector ForwardVector = GetActorForwardVector();
		FVector EndTrace = ((ForwardVector *5000.f)*StartTrace);
		FCollisionQueryParams* TraceParams = new FCollisionQueryParams();

		if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams)) {
			DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
		}
		FRotator NewRotation = FRotator(0.f, 0.5f, 0.f);

		FQuat QuatRotation = FQuat(NewRotation);

		AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	}
}

// Called to bind functionality to input
void ALabyBotPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALabyBotPawn::MoveForwardAxis(float value) {

}
void ALabyBotPawn::StartMovingForward() {

}
void ALabyBotPawn::StopMovingForward() {

}

