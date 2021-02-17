// Aun "Skippern" Johnsen 2021
#include "RMStat.h"

RMStat::RMStat()
{
}

void RMStat::Init(FString Name, int32 Temp, int32 Pot, int32 Race)
{
    StatShortName = Name;
    TempsStat = Temp;
    PotStat = Pot;
    RaceBonus = Race;
}

int32 RMStat::GetSpecialBonus() const { return SpecialBonus; }
int32 RMStat::GetRaceBonus() const { return RaceBonus; }
int32 RMStat::GetPotStat() const { return PotStat; }
int32 RMStat::GetTempStat() const { return TempsStat; }
FString RMStat::GetShortName() const { return StatShortName; }

FString RMStat::GetName() const
{
    return TEXT("");
    // switch (StatShortName) {
    //     case TEXT("AG"):
    //         return "Agility";
    //     default:
    //         UE_LOG(LogTemp, Error, TEXT("RMStat.cpp: GetName called on stat with invalid StatShortName!"));
    //         return "Unknown Error";
    // }
}

void RMStat::AlterSpecialBonus(int32 delta)
{
    SpecialBonus += delta;
}

int32 RMStat::GetBasicBonus() const
{
    if (TempsStat > 101) return 14;
    switch (TempsStat) {
        case 1:
            return -10;
        case 2:
        case 3:
            return -9;
        case 4:
        case 5:
            return -8;
        case 6:
        case 7:
            return -7;
        case 8:
        case 9:
            return -6;
        case 10:
            return -5;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            return -4;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            return -3;
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            return -2;
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
            return -1;
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
            return 1;
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            return 2;
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
            return 3;
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            return 4;
        case 90:
        case 91:
            return 5;
        case 92:
        case 93:
            return 6;
        case 94:
        case 95:
            return 7;
        case 96:
        case 97:
            return 8;
        case 98:
        case 99:
            return 9;
        case 100:
            return 10;
        case 101:
            return 12;
        default:
            return 0;
    }
}

int32 RMStat::GetTotalBonus() const
{
    return GetBasicBonus() + RaceBonus + SpecialBonus;
}
