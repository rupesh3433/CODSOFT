/*
TASK - 1
------------------- NUMBER GUESSING GAME ------------------
Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "\nWelcome to the Number Guessing Game!\n";
    cout << "Can you guess the secret number between 1 and 100?\n";

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > secretNumber)
        {
            cout << "Too high! Try again.\n";
        }
        else if (guess < secretNumber)
        {
            cout << "Too low! Try again.\n";
        }
        else
        {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n\n";
        }

    } while (guess != secretNumber);

    return 0;
}
