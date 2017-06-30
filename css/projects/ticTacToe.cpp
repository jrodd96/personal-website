///=============================================================
///
///     TIC TAC TOE PROGRAM
///     PROGRAMMER: JARED STEVENS
///     DATE: 06/13/2017
///     FILE: ticTacToe.cbp
///
///=============================================================
#include <iostream>
#include <graphics.h>
#include <stdio.h>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkWin();
void board();
int game();

int main() {

    char playChoice = ' ';

    game();
    cout << "\n\nPlay again? (Y/N): ";
    cin >> playChoice;

    while(playChoice != 'y' && playChoice != 'Y' && playChoice != 'n' && playChoice != 'N') {
        cout << "\n\nPlay again? (Y/N): ";
        cin >> playChoice;
    }
    if(playChoice == 'y' || playChoice == 'Y') {
        game();
    }
    else if(playChoice == 'n' || playChoice == 'N')
        return 0;

}
///==============================================================///
///                                                              ///
///                    MAIN GAME FUNCTION                        ///
///                                                              ///
///==============================================================///
int game() {

    int player = 1,i,choice;

    char mark;

    do {
        board();
        player = (player%2)?1:2;

        cout << "\n Player " << player << ", enter a number 1-9: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if(choice == 1 && square[1] == '1')
            square[1] = mark;
        else if(choice == 2 && square[2] == '2')
            square[2] = mark;
        else if(choice == 3 && square[3] == '3')
            square[3] = mark;
        else if(choice == 4 && square[4] == '4')
            square[4] = mark;
        else if(choice == 5 && square[5] == '5')
            square[5] = mark;
        else if(choice == 6 && square[6] == '6')
            square[6] = mark;
        else if(choice == 7 && square[7] == '7')
            square[7] = mark;
        else if(choice == 8 && square[8] == '8')
            square[8] = mark;
        else if(choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkWin();
        player++;
    }while(i == -1);

    board();

    if(i == 1) {
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';

        cout << "==>\aPlayer " << --player << " wins";
    }
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;

}
///==============================================================///
///                                                              ///
///              FUNCTION TO RETURN GAME STATUS                  ///
///               1 FOR GAME OVER WITH RESULT                    ///
///               -1 FOR GAME IS IN PROGRESS                     ///
///              0 FOR GAME OVER AND NO RESULT                   ///
///                                                              ///
///==============================================================///
int checkWin() {

    if(square[1] == square[2] && square[2] == square[3])
        return 1;
    else if(square[4] == square[5] && square[5] == square[6])
        return 1;
    else if(square[7] == square[8] && square[8] == square[9])
        return 1;
    else if(square[1] == square[4] && square[4] == square[7])
        return 1;
    else if(square[2] == square[5] && square[5] == square[8])
        return 1;
    else if(square[3] == square[6] && square[6] == square[9])
        return 1;
    else if(square[1] == square[5] && square[5] == square[9])
        return 1;
    else if(square[3] == square[5] && square[5] == square[7])
        return 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4'
            && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8'
            && square[9] != '9')
                return 0;
    else
        return -1;

}
///================================================================///
///                                                                ///
///     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYER MARKS    ///
///                                                                ///
///================================================================///
void board() {

    system("cls");
    cout << "****************************";
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "****************************\n\n";
    cout << " Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "        |       |       " << endl;
    cout << "    " << square[1] << "   |   " << square[2] << "   |   " << square[3] << endl;

    cout << " _______|_______|_______" << endl;
    cout << "        |       |       " << endl;

    cout << "    " << square[4] << "   |   " << square[5] << "   |   " << square[6] << endl;

    cout << " _______|_______|_______" << endl;
    cout << "        |       |       " << endl;

    cout << "    " << square[7] << "   |   " << square[8] << "   |   " << square[9] << endl;

    cout << "        |       |       " << endl;


}
///================================================================
