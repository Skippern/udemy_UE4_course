//
//  main.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/9/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//
/*
 This is the console executable, that makes use of the of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all
 user interaction, for game logic see the fBullCowGame class
 */

#include "main.h"
#include <iostream>
#include "fBullCowGame.hpp"

fBullCowGame BCGame; // instantiate a new game

using FText = std::string;
using int32 = int;

// entry point for our application
int main(int argc, const char * argv[]) {
    
    do {
        PrintIntro();
        PlayGame();
    }
    while (AskToPlayAgain());

    
    return 0; // exit the application
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again? (y/n)";
    FText Response = "";
    std::getline(std::cin, Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}

// plays the game
void PlayGame() {
    BCGame.Reset();

    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
    
        FText Try = GetValidTry();
        
        
        fBullCowCount bcResult = BCGame.SubmitValidGuess(Try);
        std::cout << "Bulls = " << bcResult.Bulls;
        std::cout << " Cows = " << bcResult.Cows;
        std::cout << std::endl;
    }
    return;
}

// introduce the game
void PrintIntro() {
    
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game\n";
    std::cout << "Can you Try the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}

// get a Try from the player
FText GetValidTry() {
    eWordStatus Status = eWordStatus::Invalid;
    FText Try = "";
    do {
        Try = "";
        std::cout << "\nTry " << BCGame.GetCurrentTry() << ": Place your Try: ";
        std::getline(std::cin, Try);
        std::cout << std::endl;

        Status = BCGame.CheckTryValidity(Try);
        switch (Status)
        {
            case eWordStatus::Wrong_Length:
                std::cout << "Please enter a " \
                    << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case eWordStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
                break;
            case eWordStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            case eWordStatus::OK:
                return Try;
            default:
                std::cout << "Something went wrong!";
        }
    } while (Status != eWordStatus::OK); // keep looping until no errors
    return Try;
}
