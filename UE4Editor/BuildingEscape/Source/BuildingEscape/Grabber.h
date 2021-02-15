// Aun "Skippern" Johnsen 2021

#pragma once

#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandler = nullptr;
	UInputComponent* InputHandler = nullptr;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	void Grab();
	void Release();
	void SetupInputHandler();
	FVector GetLineTraceEnd();
	// Return the first actor within reach with physics body 
	FHitResult GetFirstPhysicsBodyInReach();
};
