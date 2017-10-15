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

class fBullCowGame {
    
public:
    fBullCowGame(); // Constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); // TODO make a more rich return value
    bool CheckGuessValidity(std::string);
    
    
    
private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsogram(std::string);
    
};


#endif /* fBullCowGame_hpp */


