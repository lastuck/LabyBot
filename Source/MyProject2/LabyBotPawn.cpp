// Fill out your copyright notice in the Description page of Project Settings.


#include "LabyBotPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine.h"
#include "DrawDebugHelpers.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor::Green, text)

// Sets default values
ALabyBotPawn::ALabyBotPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);
	CurrentLocation = this->GetActorLocation();
	ShouldMove = false;
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
		if (ShouldMove) {
			SetActorLocation(CurrentLocation);

			FHitResult* HitResult = new FHitResult();
			FVector ForwardVector = GetActorForwardVector();
			ForwardVector *= 100;
			FVector UpVector = GetActorUpVector();
			UpVector *= 100;
			FVector StartTrace = this->GetActorLocation() + ForwardVector + UpVector;
			FVector EndTrace = ((ForwardVector *.5f) + StartTrace);
			FCollisionQueryParams* TraceParams = new FCollisionQueryParams();


			if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams)) {
				//DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
				FRotator NewRotation = FRotator(0.f, -90.f, 0.f);
				FQuat QuatRotation = FQuat(NewRotation);
				AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
			}

			CurrentLocation += GetActorForwardVector() * 600.0f * DeltaTime;
		}
	}
}

// Called to bind functionality to input
void ALabyBotPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("LeftMouse", IE_Pressed, this, &ALabyBotPawn::DebugMouse);
}

void ALabyBotPawn::DebugMouse() {
	print("labypressed");
}

