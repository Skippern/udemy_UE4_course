// Aun "Skippern" Johnsen 2021
#include "StatHandler.h"

// Sets default values for this component's properties
UStatHandler::UStatHandler()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStatHandler::BeginPlay()
{
	Super::BeginPlay();

	// Initiates the individual Stats
	RMStat tmpStat;
	tmpStat.Init(TEXT("AG"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("CO"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("ME"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("RE"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("SD"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("EM"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("IN"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("PR"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("QU"), 90, 100, 0);
	Stats.Add(tmpStat);
	tmpStat.Init(TEXT("ST"), 90, 100, 0);
	Stats.Add(tmpStat);
}

void UStatHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


