//
//  main.cpp
//  BullCowGame
//
//  Created by Aun Johnsen on 10/9/17.
//  Copyright © 2017 Aun Johnsen. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // introduce the game
    constexpr int WORD_LENGTH = 5;
    
    cout << "Welcome to Bulls and Cows, a fun word game\n";
    cout << "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram I'm thinking of?\n";

    // get a guess from the player
    string Guess = "";
    cout << "\nPlace your guess: ";
    cin >> Guess;
    cout << endl;
    // repeat the guess back to them
    cout << "You guessed: " << Guess << endl;
    
    cout << endl;
    return 0;
}
