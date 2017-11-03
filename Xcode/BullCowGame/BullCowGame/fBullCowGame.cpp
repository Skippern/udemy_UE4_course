//
//  fBullCowGame.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/15/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//
#include "fBullCowGame.hpp"

fBullCowGame::fBullCowGame() { fBullCowGame::Reset(); }

int32 fBullCowGame::GetCurrentTry() const { return fBullCowGame::MyCurrentTry; }
int32 fBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool fBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 fBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLenthToMaxTries { {1, 2}, {2, 3}, {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20}, {8, 30}, {9, 45}, {10, 60} };
    return WordLenthToMaxTries[GetHiddenWordLength()];
}

void fBullCowGame::Reset()
{
    const FString HIDDEN_WORD = "planet";

    bGameIsWon = false;
    fBullCowGame::MyCurrentTry = 1;
    MyHiddenWord = HIDDEN_WORD;
    
    return;
}

bool fBullCowGame::IsIsogram(FString word) const
{
    TMap<char, bool> LetterSeen;
    
    for(auto letter : word)
    {
        letter = tolower(letter);
        if ( LetterSeen[letter] == true) return false;
        LetterSeen[letter] = true;
    }
    
    return true;
}

bool fBullCowGame::IsLowercase(FString word) const
{
    for (auto letter : word)
    {
        if (letter != islower(letter)) return false;
    }
    return true;
}

eWordStatus fBullCowGame::CheckTryValidity(FString Try) const
{
    if (!IsIsogram(Try))
    {
        return eWordStatus::Not_Isogram;
    } else if (!IsLowercase(Try))
    {
        return eWordStatus::Not_Lowercase;
    } else if (Try.length() != GetHiddenWordLength())
    {
        return eWordStatus::Wrong_Length;
    } else
    {
        return eWordStatus::OK;
    }
}

fBullCowCount fBullCowGame::SubmitValidGuess(FString Guess) {
    
    MyCurrentTry++;
    fBullCowCount BullCowCount;
    for (int32 i = 0; i < MyHiddenWord.length(); i++) {
        bool isMatch = false;
        bool isBullMatch = false;
        for (int32 j = 0; j < Guess.length(); j++) {
            if (MyHiddenWord[i] == Guess[j]) {
                if (i == j) isBullMatch = true;
                else isMatch = true;
            }
        }
        if (isBullMatch) BullCowCount.Bulls++;
        else if (isMatch) BullCowCount.Cows++;
        std::cout << std::endl;
    }
    
    if (BullCowCount.Bulls == GetHiddenWordLength()) {
        bGameIsWon = true;
    } else {
        bGameIsWon = false;
    }
    
    return  BullCowCount;
}
