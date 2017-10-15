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

    for (int count = 0; count < NUMBER_OF_TURNS; count++) {
        std::string Guess = GetGuess();
        PrintBack(Guess);
        std::cout << std::endl;
    }
    return;
}

void PrintBack(std::string Guess) {
    std::cout << "You guessed: " << Guess << std::endl;

}

// introduce the game
void PrintIntro() {
    
    std::cout << "Welcome to Bulls and Cows, a fun word game\n";
//    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    
    return;
}

// get a guess from the player
std::string GetGuess() {
    std::string Guess = "";
    std::cout << "\nPlace your guess: ";
    std::getline(std::cin, Guess);
    std::cout << std::endl;

    return Guess;
}
