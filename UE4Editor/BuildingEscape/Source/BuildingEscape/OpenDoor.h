// Aun "Skippern" Johnsen 2021
#pragma once

#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindSoundComponent();

private:
	FRotator DoorState;
	float ClosedAngle;
	// float DoorLastOpenedTime = 0.f;
	bool bDoorSoundIndicator = false;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;
	
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorOpeningSpeed = .8f;

	UPROPERTY(EditAnywhere)
	float DoorClosingSpeed = 5.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 80.f;

	UPROPERTY()
	UAudioComponent* SoundComponent = nullptr;

};
