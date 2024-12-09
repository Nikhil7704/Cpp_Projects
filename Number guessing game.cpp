#include <iostream>
#include <ctime>
using namespace std;

// Function for the number guessing game
void number_guessing_game(int random_num, int &guess, int &tries) {
    cout << "You have " << tries << " tries to guess the number." << endl;

    while (tries > 0) {
        cout << "Please enter your guess: ";
        cin >> guess;

        if (guess == random_num) {
            cout << "Congratulations! You have successfully guessed the number!" << endl;
            return; // Exit the function as the user guessed correctly
        } else {
            tries--; // Reduce the number of tries
            if (tries == 0) {
                cout << "You have no tries left. Game over!" << endl;
                cout << "The correct number was: " << random_num << endl;
                return; // Exit the function as the user is out of tries
            } else {
                cout << "Incorrect guess. Please try again." << endl;
                cout << "Tries left: " << tries << endl;
            }
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int random_num = rand() % 10 + 1; // Generate a random number between 1 and 10
    int guess;
    int tries = 5;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "********************************************" << endl;
    cout << "A random number between 1 and 10 has been generated." << endl;

    // Call the game function
    number_guessing_game(random_num, guess, tries);

    return 0;
}
