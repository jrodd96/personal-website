#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <graphics.h>

using namespace std;

void drawLine(int n, char symbol);
void rules();

int main() {

    string playerName;
    int amount;  // hold player balance amount
    int bettingAmount;
    int guess;
    int dice;   // hold computer-generated number
    char choice;

    srand(time(0));  // "Seed" the random generator

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n" << endl;
    drawLine(60, '_');

    cout << "\n\n Enter your name: ";
    getline(cin, playerName);

    cout << "\n\n Enter deposit amount to play game: ";
    cin >> amount;

    do {
        system("cls");
        rules();
        cout << "\n\n Your current balance is $" << amount << endl;

              // Get player's betting amount

        do {
            cout << "\n" << playerName << ", enter money to bet: $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is higher than your total amount..." << endl;
        }while(bettingAmount > amount);

        do {
            cout << "\n Guess your number to bet 1 through 10: ";
            cin >> guess;
            if(guess <= 0 || guess > 10) {
                cout << "\nPlease check the number! " << endl;
                cout << "Renter data: ";
            } // end if

        }while(guess <= 0 || guess > 10); //end do while

        dice = rand()%10 + 1; // Will hold random number

        if(dice == guess) {
            cout << "\n\nCongratulations! You won $" << bettingAmount * 10;
            amount = amount - bettingAmount;
        }
        else {
            cout << "\n\nBad luck this time... You lost $" << bettingAmount << endl;
            amount = amount - bettingAmount;
        }
        cout << "\nThe winning number was: " << dice << endl;
        cout << "\n\n" << playerName << ", you have $" << amount << " remaining total amount." << endl;
        if(amount == 0) {
            cout << "\nYou have no more money to play..." << endl;
            break;
        }
        cout << "\n\n Play again? (Y/N): ";
        cin >> choice;

    }while(choice == 'Y' || choice == 'y'); //end do

    cout << "\n\n" << endl;
    drawLine(70, '=');
    cout << "\n\nThanks for playing. Your balance amount is $" << amount << endl << endl;
    drawLine(70, '=');
    return 0;

}
///=================================================================
void drawLine(int n, char symbol) {

    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n";

}
///===========================================================
void rules() {

    system("cls");
    cout << endl << endl;
    drawLine(80, '-');
    cout << "\t\tRULES" << endl;
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 and 10" << endl;
    cout << "\t2. Win: 10x bet amount added to total amount" << endl;
    cout << "\t3. Lose: Betting amount subtracted from total amount" << endl;
    drawLine(80, '-');

}
///===========================================================
