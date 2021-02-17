// Aun "Skippern" Johnsen 2021
#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MEDIEVALESCAPE_API RMStat
{
public:
	RMStat();
	void Init(FString Name, int32 Temp, int32 Pot, int32 Race);

	int32 GetBasicBonus() const;
	int32 GetTotalBonus() const;
	int32 GetTempStat() const;
	int32 GetPotStat() const;
	int32 GetRaceBonus() const;
	int32 GetSpecialBonus() const;
	FString GetShortName() const;
	FString GetName() const;

	void AlterSpecialBonus(int32 delta);

private:
	FString StatShortName = TEXT("");
	int32 TempsStat = 60;
	int32 PotStat = 100;
	int32 RaceBonus = 0;
	int32 SpecialBonus = 0;
};
