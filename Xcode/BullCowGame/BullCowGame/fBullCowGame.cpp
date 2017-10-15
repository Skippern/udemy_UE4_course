//
//  fBullCowGame.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/15/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//

#include "fBullCowGame.hpp"

fBullCowGame::fBullCowGame() { fBullCowGame::Reset(); }

int fBullCowGame::GetMaxTries() const { return fBullCowGame::MyMaxTries; }
int fBullCowGame::GetCurrentTry() const { return fBullCowGame::MyCurrentTry; }

void fBullCowGame::Reset()
{
//    constexpr int WORD_LENGTH = 5;
    constexpr int MAX_TRIES = 5;
    fBullCowGame::MyMaxTries = MAX_TRIES;
    
    fBullCowGame::MyCurrentTry = 1;
    
    return;
}

bool fBullCowGame::IsGameWon() const
{
    return false;
}

bool fBullCowGame::CheckGuessValidity(std::string)
{
    return false;
}
