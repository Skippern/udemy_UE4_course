//
//  fBullCowGame.hpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/15/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//
#pragma once


#ifndef fBullCowGame_hpp
#define fBullCowGame_hpp

#include <stdio.h>
#include <iostream>

using FString = std::string;
using int32 = int;

struct fBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

class fBullCowGame {

public:
    fBullCowGame(); // Constructor
    
    int32 GetMaxTries() const;
    int32 GetHiddenWordLength() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    bool CheckTryValidity(FString) const;

    void Reset(); // TODO make a more rich return value
    fBullCowCount SubmitGuess(FString);
    
    
private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram(FString);
    FString MyHiddenWord;
    
};


#endif /* fBullCowGame_hpp */


