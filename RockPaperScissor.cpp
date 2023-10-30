#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    while (true) {
        int computerChoice = rand() % 3;  // 0 for Rock, 1 for Paper, 2 for Scissors
        int userChoice;

        cout << "Rock Paper Scissors Game\n";
        cout << "0 - Rock, 1 - Paper, 2 - Scissors, 3 - Quit: ";
        cin >> userChoice;

        if (userChoice < 0 || userChoice > 3) {
            cout << "Invalid choice. Please choose a valid option.\n";
            continue;
        }

        if (userChoice == 3) {
            cout << "Thanks for playing. Goodbye!\n";
            break;
        }

        cout << "Computer's choice: ";
        switch (computerChoice) {
            case 0: cout << "Rock\n"; break;
            case 1: cout << "Paper\n"; break;
            case 2: cout << "Scissors\n"; break;
        }

        cout << "Your choice: ";
        switch (userChoice) {
            case 0: cout << "Rock\n"; break;
            case 1: cout << "Paper\n"; break;
            case 2: cout << "Scissors\n"; break;
        }

        if (userChoice == computerChoice) {
            cout << "It's a tie!\n";
        } else if ((userChoice == 0 && computerChoice == 2) || 
                   (userChoice == 1 && computerChoice == 0) || 
                   (userChoice == 2 && computerChoice == 1)) {
            cout << "You win!\n";
        } else {
            cout << "Computer wins!\n";
        }
    }

    return 0;
}
