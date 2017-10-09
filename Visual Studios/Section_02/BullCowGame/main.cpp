// main.cpp
// 09-10-2017 Aun Johnsen
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ubtriduce the game
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;

	// get a guess from the player
	string Guess = "";
	cout << endl << "Enter your guess: ";
	cin >> Guess;
	cout << endl;

	// repeat the guess back to them
	cout << "You guessed: " << Guess << endl;

	cout << endl;
	return 0;
}