//
//  main.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/9/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//

#include "main.h"
#include <iostream>

using namespace std;



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
    cout << "Do you want to play again? (y/n)";
    string Response = "";
    getline(cin, Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}

// plays the game
void PlayGame() {
    constexpr int NUMBER_OF_TURNS = 5;

    for (int count = 0; count < NUMBER_OF_TURNS; count++) {
        string Guess = GetGuess();
        PrintBack(Guess);
        cout << endl;
    }
    return;
}

void PrintBack(string Guess) {
    cout << "You guessed: " << Guess << endl;

}

// introduce the game
void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    
    cout << "Welcome to Bulls and Cows, a fun word game\n";
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";
    
    return;
}

// get a guess from the player
string GetGuess() {
    string Guess = "";
    cout << "\nPlace your guess: ";
    getline(cin, Guess);
    cout << endl;

    return Guess;
}
