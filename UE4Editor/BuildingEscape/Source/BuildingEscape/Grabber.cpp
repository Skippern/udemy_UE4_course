// Aun "Skippern" Johnsen 2021
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandler) UE_LOG(LogTemp, Error, TEXT("Grabber.cpp: No PhysicsHandler Component found on %s!"), *GetOwner()->GetName())
	SetupInputHandler();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandler->GrabbedComponent)
	{
		PhysicsHandler->SetTargetLocation(GetLineTraceEnd());
	}
}

void UGrabber::SetupInputHandler()
{
	InputHandler = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputHandler)
	{
		InputHandler->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputHandler->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Grabber.cpp: No InputHandler Component found on %s!"), *GetOwner()->GetName() );
	}
}

void UGrabber::Grab()
{
	FHitResult TargetItem = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* CarriedObject = TargetItem.GetComponent();
	if (PhysicsHandler && TargetItem.GetActor())
	{
		PhysicsHandler->GrabComponentAtLocation(
			CarriedObject,
			NAME_None,
			GetLineTraceEnd()
		);
	}
}

void UGrabber::Release()
{
	if (PhysicsHandler && PhysicsHandler->GrabbedComponent)
	{
		PhysicsHandler->ReleaseComponent();
	}
}

FVector UGrabber::GetLineTraceEnd()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		GetLineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	return Hit;
}
