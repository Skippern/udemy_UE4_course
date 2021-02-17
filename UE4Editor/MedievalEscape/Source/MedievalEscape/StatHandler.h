// Aun "Skippern" Johnsen 2021
#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "lib/RMStat.h"
#include "StatHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEDIEVALESCAPE_API UStatHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatHandler();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<RMStat> Stats;
		
};
