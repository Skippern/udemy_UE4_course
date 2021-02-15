// Aun "Skippern" Johnsen 2021
#include "OpenDoor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate) UE_LOG(LogTemp, Error, TEXT("OpenDoor.cpp: %s has no pressure plate assigned!"), *GetOwner()->GetName());
	DoorState = GetOwner()->GetActorRotation();
	ClosedAngle = DoorState.Yaw;
	OpenAngle += DoorState.Yaw;

	FindSoundComponent();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate && TotalMassOfActors() > TriggerMass )
	{
		OpenDoor(DeltaTime);
		// DoorLastOpenedTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		CloseDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	DoorState.Yaw = FMath::Lerp(DoorState.Yaw, OpenAngle, DeltaTime * DoorOpeningSpeed);
	GetOwner()->SetActorRotation(DoorState);

	if (bDoorSoundIndicator)
	{
		SoundComponent->Play();
		bDoorSoundIndicator = false;
	}
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	DoorState.Yaw = FMath::Lerp(DoorState.Yaw, ClosedAngle, DeltaTime * DoorClosingSpeed);
	GetOwner()->SetActorRotation(DoorState);

	if (!bDoorSoundIndicator)
	{
		SoundComponent->Play();
		bDoorSoundIndicator = true;
	}

}

void UOpenDoor::FindSoundComponent()
{
	SoundComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if (!SoundComponent) UE_LOG(LogTemp, Error, TEXT("OpenDoor.cpp: %s missing audio component!"), *GetOwner()->GetName());
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
	// Find all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (PressurePlate) PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	// Add Up Their Masses
	for (AActor* Overlapper : OverlappingActors)
	{
		TotalMass += Overlapper->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}