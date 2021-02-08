/*
 * tripleX game
 * 
 * a simple game to learn C++
 */
#include <iostream>
#include <ctime>

void PrintIntroduction(int Level)
{
    // Print a welcome message
    std::cout << "You are a secret agent breaking into a level " << Level << " secure server room.\n";
    std::cout << "Enter he correct code to continue...\n\n";
}

bool PlayGame(int Level)
{
    // Declare 3 number code
    int CodeA = Level + rand() % Level;
    int CodeB = Level + rand() % Level;
    int CodeC = Level + rand() % Level;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl << std::endl;
    std::cout << "\tThere are 3 numbers in the code.\n";
    std::cout << "\tThe codes add-up to: " << CodeSum << "\n";
    std::cout << "\tThe codes multiply to give: " << CodeProduct << "\n";

    // Store player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "The door opens!\n\n";
        return true;
    }
    else
    {
        std::cout << "ALERT!\n\tWrong code, alarm goes off!!!\nALERT!\n";
        return false;
    }
}

/*
 * Function: main
 * Arguments: none
 * Return: game return code, 0 for normal condition
 */
int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        PrintIntroduction(LevelDifficulty);
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors in CIN
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            // Increase level difficulty
            LevelDifficulty++;
        }
    }
    std::cout << "Congratulation, you are now in the inner server room, lets grab the data and scram!\n\n";
    return 0;
}
