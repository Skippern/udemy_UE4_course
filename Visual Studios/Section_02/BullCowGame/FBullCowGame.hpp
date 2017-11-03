//
// FBullCowGame.hpp
//
// Created by Aun Johnsen on 11/03/2017
// Copyright (c) 2017 Aun Johnsen. All rights reserved.
//
#pragma once

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <iostream>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class eWordStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame {

public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	eWordStatus CheckTryValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	FString MyHiddenWord;
	bool bGameIsWon;
};

#endif
