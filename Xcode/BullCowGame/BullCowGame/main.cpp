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

    for (int32 count = 0; count < 5; count++) {
        FText Try = GetTry();
        fBullCowCount bcResult = BCGame.SubmitGuess(Try);
        std::cout << "Bulls = " << bcResult.Bulls;
        std::cout << " Cows = " << bcResult.Cows;
        std::cout << std::endl;
    }
    return;
}

// introduce the game
void PrintIntro() {
    
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
    std::cout << "Can you Try the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}

// get a Try from the player
FText GetTry() {
    FText Try = "";
    std::cout << "\nPlace your Try: ";
    std::getline(std::cin, Try);
    std::cout << std::endl;

    return Try;
}
