#include "std_lib_facilities.h"
#include "utilities.h"
#include "mastermind.h"

void playMastermind(void)
{
    const int size = 4;
    const int letters = 6;
    const int maxTries = 10;
    string code;
    string guess;
    code = randomizeString(size, 'A', 'A' + (letters-1));
    int tries = 0;
    
    while (checkCharactersAndPosition(guess, code) < size && tries < maxTries)
    {
        cout << "\nEnter a word containing characters between A and "
             << static_cast<char>('A' + letters - 1) << ", in order to create a string of length "
             << size << endl;
        cout << "Your guess: ";
        guess = readInputToString(size, 'A', 'A' + (letters - 1));
        cout << "Correct characters and position: " << checkCharactersAndPosition(guess, code) << endl;
        cout << "Correct characters: " << checkCharacters(guess, code, letters) << endl;
        tries++;

        if (tries == maxTries)
        {
            cout << "\nYou have reached the maximum number of tries." << endl;
            cout << "The code was: " << code << endl;
            return;
        }
    }
    cout << "\nYou guessed the code! (" << code << ")" << endl;
}

int checkCharactersAndPosition(string guess, string code)
{
    int correct = 0;
    for (unsigned i = 0; i < guess.length(); i++)
    {
        if (guess[i] == code[i])
        {
            correct++;
        }
    }
    return correct;
}

int checkCharacters(string guess, string code, int letters)
{
    int correct = 0;
    for (char letter = 'A'; letter < 'A' + letters - 1; letter++)
    {
        if (countChar(code, letter) > 0 && countChar(guess, letter) > 0)
        {
            correct++;
        }
    }
    return correct;
}