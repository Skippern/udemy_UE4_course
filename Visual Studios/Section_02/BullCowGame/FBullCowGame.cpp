//
// FBullCowGame.cpp
//
// Created by Aun Johnsen 11/03/2017
// Copyright (c) 2017 Aun Johnsen. All rights reserved.
//
#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return FBullCowGame::MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries
{
	TMap<int32, int32> WordLengthToMaxTries { {1, 2}, {2, 3}, {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };
	return WordLengthToMaxTries[FBullCowGame::GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	bGameIsWon = false;
	FBullCowGame::MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[letter] == true) return false;
		LetterSeen[letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) if (Letter != tolower(Letter)) return false;
	return true;
}

eWordStatus FBullCowGame::CheckTryValidity(FString Try) const
{
	if (!IsIsogram(Try))
	{
		return eWordStatus::Not_Isogram;
	}
	else if (!IsLowercase(Try))
	{
		return eWordStatus::Not_Lowercase;
	}
	else if (Try.length() != GetHiddenWordLength())
	{
		return eWordStatus::Wrong_Length;
	}
	else {
		return eWordStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValdiGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		bool isMatch = false;
		bool isBullMatch = false;
		for (int32 j = 0; j < Guess.length(); j++) {
			if (MyHiddenWord[i] == Guess[j]) {
				if (i == j) isBullMatch = true;
				else isMatch = true;
			}
		}
		if (isBullMatch) BullCowCount.Bull++;
		else if (isMatch) BullCowCount.Cow++;
	}

	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
}
