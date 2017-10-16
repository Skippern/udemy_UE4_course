//
//  main.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/9/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//

#include "main.h"
#include <iostream>
#include "fBullCowGame.hpp"

fBullCowGame BCGame; // instantiate a new game

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
    std::string Response = "";
    std::getline(std::cin, Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}

// plays the game
void PlayGame() {
    BCGame.Reset();

    for (int count = 0; count < 5; count++) {
        std::string Try = GetTry();
        PrintBack(Try);
        std::cout << std::endl;
    }
    return;
}

void PrintBack(std::string Try) {
    std::cout << "You Tryed: " << Try << std::endl;

}

// introduce the game
void PrintIntro() {
    
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
//    std::cout << "Can you Try the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}

// get a Try from the player
std::string GetTry() {
    std::string Try = "";
    std::cout << "\nPlace your Try: ";
    std::getline(std::cin, Try);
    std::cout << std::endl;

    return Try;
}
