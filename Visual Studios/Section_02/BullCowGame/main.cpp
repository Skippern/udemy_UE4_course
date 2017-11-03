// main.cpp
// 09-10-2017 Aun Johnsen
#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PlayGame();
void PrintIntro();
FText GetValidTry();
void PrintBack(FText Try);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PlayGame() {
	BCGame.Reset();
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
		FText Try = GetValidTry();

		FBullCowCount bcResult = BCGame.SubmitValidGuess(Try);
		std::cout << "Bulls = " << bcResult.Bulls;
		std::cout << " Cows = " << bcResult.Cows;
		std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}

void PrintIntro() {
	eWordStatus = eWordStatus::Invalid;
	FText Try = "";
	do {
		Try = "";
		std::cout << "\n\nTry " << BCGame.GetCurrentTry() << " / " << BCGame.GetMaxTries() << ": Place your Try: ";
		std::getline(std::cin, Try);
		std::cout << std:endl;

		Status = BCGame.CheckTryValidity(Try);
		switch (Status)
		{
		case eWordStatus::Wrong_Length:
			std::cout << "Pleace enter a " \
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
	} while (Status != eWordStatus::OK);
	return Try;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations, you won!" << std::endl;
	}
	else {
		std::cout << "BAD LUCK!" << std::endl;
	}
	return;
}
