// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Hi There!"));
    Isograms = GetValidWords(CommonWords);
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("default");
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    Lives = HiddenWord.Len();
    bGameOver = false;


    PrintLine(TEXT("Welcome to Bulls & Cow game."));
    PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type the word and press <enter> to continue ..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nThe Game has ended, press <enter> to start again.\n"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess.ToUpper() == HiddenWord.ToUpper())
    {
        PrintLine(TEXT("Congratulations, you won!"));
        EndGame();
        return;
    }
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Wrong length word, make sure the word is %i letters long."), HiddenWord.Len());
        return;
    }
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("Your guess is not an isogram, try again."));
        return;
    }
    // count bulls & cows
    FBullCowCount Score = GetBullCows(Guess);
    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);
    if (Lives > 1)
    {
        PrintLine(TEXT("Sorry, wrong word, you lost a life."));
        PrintLine(TEXT("You nave have %i lives left."), --Lives);
    }
    else
    {
        PrintLine(TEXT("Wrong again! You lost!"));
        PrintLine(TEXT("The hidden word was [%s]"), *HiddenWord);
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for (int32 i = 0; i < Word.Len(); i++)
    {
        for(int32 j = i + 1; j < Word.Len(); j++)
        {
            if (Word[i] == Word[j]) return false;
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> Output;

    for (FString Element : WordList)
    {
        if (IsIsogram(Element) && Element.Len() > 3 && Element.Len() < 9) Output.Emplace(Element);
    }    
    return Output;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;
    for (int32 i = 0; i < Guess.Len(); i++)
    {
        if (Guess[i] == HiddenWord[i])
        {
            Count.Bulls++;
            continue;
        }
        for (int32 j = 0; j < Guess.Len(); j++)
        {
            if (j != i && Guess[i] == HiddenWord[j])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}
