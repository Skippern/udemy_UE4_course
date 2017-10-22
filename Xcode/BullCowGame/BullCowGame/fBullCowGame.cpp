//
//  fBullCowGame.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/15/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//

#include "fBullCowGame.hpp"


fBullCowGame::fBullCowGame() { fBullCowGame::Reset(); }

int32 fBullCowGame::GetMaxTries() const { return fBullCowGame::MyMaxTries; }
int32 fBullCowGame::GetCurrentTry() const { return fBullCowGame::MyCurrentTry; }
int32 fBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void fBullCowGame::Reset()
{
//    constexpr int32 WORD_LENGTH = 5;
    constexpr int32 MAX_TRIES = 5;
    const FString HIDDEN_WORD = "planet";

    fBullCowGame::MyMaxTries = MAX_TRIES;
    fBullCowGame::MyCurrentTry = 1;
    MyHiddenWord = HIDDEN_WORD;
    
    return;
}

bool fBullCowGame::IsGameWon() const
{
    return false;
}

eWordStatus fBullCowGame::CheckTryValidity(FString Try) const
{
    if (false) // Not an isogram
    {
        return eWordStatus::Not_Isogram;
    } else if (false) // Not lowercase
    {
        return eWordStatus::Not_Lowercase;
    } else if (Try.length() != GetHiddenWordLength()) // wrong length
    {
        return eWordStatus::Wrong_Length;
    } else
    {
        return eWordStatus::OK;
    }
}

fBullCowCount fBullCowGame::SubmitValidGuess(FString Guess) {
    
    // increase turn number
    MyCurrentTry++;
    // setup return variable
    fBullCowCount BullCowCount;
    // loop through all letters in the guess
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
    
    return  BullCowCount;
}
