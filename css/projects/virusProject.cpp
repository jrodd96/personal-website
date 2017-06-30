#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <graphics.h>
#include <fstream>
#include <windows.h> //header for gotoxy

using namespace std;

COORD coord={0,0}; //global variable for gotoxy

void SetColor(int ForgC);
void gotoxy(int x, int y);

int main() {

    system("cls");  //to clear the console screen

    for(int i=0; i<100; i++) {
        SetColor(14);
        gotoxy(35,12);
        SetColor(2);
        cout << i << "%";
        delay(75);
        system("cls");
    }

    delay(100);
    system("cls");
    fflush(NULL);  //for flushing output stream
    gotoxy(20,12);
    cout << " 'SUPERNOVA' VIRUS CREATED NOW BY AEGISLASH";
    gotoxy(20,14);
    cout << "SAY GOODBYE TO YOUR PC IN";
    for(int j=10; j>=0; j--) {
        gotoxy(48,14);
        cout << j << " SECONDS...";
        delay(1000);
    }
    system("cls");
    cout << "\n\t1. HARD-DISK CORRUPTION: ";
    delay(4000);
    cout << "completed" << endl;
    cout << "\n\t2. MOTHERBOARD CORRUPTION: ";
    delay(4000);
    cout << "completed" << endl;
    for(int i=0; i<100; i++) {
        cout << "\n\t3. INSTALLING 'CYBERBOB.DLL' --> C:/WINDOWS/COMMAND: " << i << "%";
        delay(150);
        system("cls");
    }
    delay(2000);
    cout << "\n\n\tPROCRAETORIAN.SYS SUCCESSFULLY INSTALLED" << endl;
    delay(3000);
    system("cls");
    gotoxy(35,12);
    cout << "RUNNING 'VIRUS.EXE'" << endl;
    delay(4000);
    system("cls");
    gotoxy(35,12);
    cout << "**************************" << endl;
    cout << "      JUST KIDDING...     " << endl;
    cout << "**************************" << endl;
    return 0;

}
///===================================================================
void SetColor(int ForgC) {  //function to set text color

  WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
  if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {

                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);

  }

  /*

        Name         | Value
                     |
        Black        |   0
        Blue         |   1
        Green        |   2
        Cyan         |   3
        Red          |   4
        Magenta      |   5
        Brown        |   6
        Light Gray   |   7
        Dark Gray    |   8
        Light Blue   |   9
        Light Green  |   10
        Light Cyan   |   11
        Light Red    |   12
        Light Magenta|   13
        Yellow       |   14
        White        |   15

  */

 return;

}
///=======================================================
void gotoxy(int x,int y) { //function to use gotoxy

    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
///=====================================================
