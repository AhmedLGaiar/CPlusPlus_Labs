#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//To Move Cursor to X and Y
void gotoxy1(int x, int y);

//To Change Color
void SetColorAndBackground(int ForgC, int BackC);

int main() {

    
    
    return 0;
}

void gotoxy1(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//To Change Color
void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

#pragma region Colors
/*BLACK        0
BLUE           1
GREEN          2
CYAN           3
RED            4
MAGENTA        5
BROWN          6
LIGHTGRAY      7
DARKGRAY       8
LIGHTBLUE      9
LIGHTGREEN     10
LIGHTCYAN      11
LIGHTRED       12
LIGHTMAGENTA   13
YELLOW         14
WHITE          15*/
#pragma endregion