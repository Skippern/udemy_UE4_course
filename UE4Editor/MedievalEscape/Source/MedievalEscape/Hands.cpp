// Aun "Skippern" Johnsen 2021
#include "Hands.h"

#define OUT
#define DEBUG true

// Sets default values for this component's properties
UHands::UHands()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UHands::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandler) UE_LOG(LogTemp, Error, TEXT("Hands.cpp: No PhysicsHandler Component found on %s!"), *GetOwner()->GetName());
	SetupInputHandler();
}
void UHands::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (DEBUG)
	{
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation);
		DrawDebugLine(
			GetWorld(),
			PlayerViewPointLocation,
			GetLineTraceEnd(),
			FColor(0, 255, 0),
			false,
			0.f,
			0,
			5.f);
	}

	if (PhysicsHandler && PhysicsHandler->GrabbedComponent)
	{
		PhysicsHandler->SetTargetLocation(GetLineTraceEnd());
	}
}

void UHands::SetupInputHandler()
{
	InputHandler = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputHandler)
	{
		InputHandler->BindAction("Grab", IE_Pressed, this, &UHands::Grab);
		InputHandler->BindAction("Grab", IE_Released, this, &UHands::Release);
		// InputHandler->BindAction("Push", IE_Repeat, this, &UHands::Push);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Hands.cpp: No InputHandler Component found on %s!"), *GetOwner()->GetName());
	}
}

void UHands::Grab()
{
	if (DEBUG) UE_LOG(LogTemp, Display, TEXT("Attempting Grab"));
	FHitResult TargetItem = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* CarriedObject = TargetItem.GetComponent();
	if (PhysicsHandler && TargetItem.GetActor())
	{
		UE_LOG(LogTemp, Display, TEXT("Trying to grab %s"), *TargetItem.GetActor()->GetName());
		PhysicsHandler->GrabComponentAtLocation(
			CarriedObject,
			NAME_None,
			GetLineTraceEnd()
		);
	}
}

void UHands::Release()
{
	if (DEBUG) UE_LOG(LogTemp, Display, TEXT("Releasing"));
	if (PhysicsHandler && PhysicsHandler->GrabbedComponent)
	{
		PhysicsHandler->ReleaseComponent();
	}
}

// void UHands::Push()
// {

// }

FVector UHands::GetLineTraceEnd()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

FHitResult UHands::GetFirstPhysicsBodyInReach()
{
	if (DEBUG) UE_LOG(LogTemp, Display, TEXT("Looking for an object to grab"));
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		GetLineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams);
	// if (DEBUG && Hit) UE_LOG(LogTemp, Display, TEXT("Found something!"));
	return Hit;
}
