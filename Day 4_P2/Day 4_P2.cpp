#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//To Move Cursor to X and Y
void gotoxy1(int x, int y);

//To Change Color
void SetColorAndBackground(int ForgC, int BackC);

class Users {
public:
    string username;
private:
	string _password;
	Users() {
		username = "";
        _password = "";
	}
	void setPassword() {
		cout << "Enter password: ";
		cin >> _password;
    }
}


int main() {

    float avg;
    const char* menu[] = { "Log in", "Register", "Exit" };
    bool isRunning = true;
    int selected = 0;

    do {

        for (int i = 0; i < 3; i++) {
            gotoxy1(60, 6 * (i + 1));
            if (i == selected) {
                SetColorAndBackground(15, 1);
            }
            else {
                SetColorAndBackground(15, 0);
            }
            cout << menu[i] << endl;
        }

        char key = _getch();
        switch (key) {
        case 72:
            --selected;
            if (selected < 0) selected = 2;
            break;
        case 80:
            ++selected;
            if (selected > 2) selected = 0;
            break;
        case 13:
            SetColorAndBackground(15, 0);

            system("cls");

            switch (selected) {
            case 0: {

                
            }

                  break;
            case 1: {

                

            }
                  break;
            case 2: {
               

            }
                  break;
            }

            cout << "\nPress any key to continue...";
            _getch();
            system("cls");
            break;
        case 27:
            isRunning = false;
            break;
        }
    } while (isRunning);

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