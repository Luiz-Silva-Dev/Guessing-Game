#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "***************************************" << endl;
    cout << "* Welcome to the Guessing Game! *" << endl;
    cout << "***************************************" << endl;

    while (true) {
    cout << "Choose the difficulty level:" << endl;
    cout << "1)Easy 2)Normal 3)Hard" << endl;
    int choice;
    cin >> choice;
    
    int difficulty;
    if (choice == 1) {
        difficulty = 15;
    }
    else if (choice == 2) {
        difficulty = 10;
    }
    else {
        difficulty = 5;
    }

    int guess;
    int chance = 0;
    srand(time(0));
    const int SECRETNUMBER = rand() % 100;
    bool incorrect = true;
    double points = 1000.0;

    while (incorrect) {
        
        if (chance < difficulty) {
            cout << "Enter the secret number: ";
            cin >> guess;

            double lostPoints = abs(guess - SECRETNUMBER)/2.0;
            bool win = guess == SECRETNUMBER;
            bool bigger = guess > SECRETNUMBER;
            points -= lostPoints;

            if (win) {
                cout << "Congratulations, you did it!" << endl;
                incorrect = false;
                cout << "The game ended with " << chance << " chances" << endl;
                cout.precision(2);
                cout << fixed;
                cout << "His score was " << points << " points" << endl;
                break;
            }
            else if (bigger){
                chance++;
                cout << "Too bad, the number is bigger than the secret number" << endl;
            }
            else{
                chance++;
                cout << "Too bad, the number is less than the secret number" << endl;
            }
        } 
        else {
            cout << "Due to many attempts, the game was terminated" << endl;
            break;
        }
    }

    return 0;
}
