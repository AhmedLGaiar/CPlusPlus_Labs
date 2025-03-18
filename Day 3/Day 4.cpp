#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

enum Choice
{
    Paper,
    Rock,
    Scissors,
};

//To Move Cursor to X and Y
void gotoxy1(int x, int y);

//To Change Color
void SetColorAndBackground(int ForgC, int BackC);

class Human {
public:
    Choice choice;

    Human() {
        choice = Choice::Paper;
    }

    void MakeChoice() {
        char key = _getch();
        switch (key) {
        case '1': choice = Choice::Paper; break;
        case '2': choice = Choice::Rock; break;
        case '3': choice = Choice::Scissors; break;
        }
    }
};

class Computer {
public:
    Choice choice;

    Computer() {
        choice = Choice::Paper;
    }

    void MakeChoice() {
        choice = static_cast<Choice>(rand() % 3); 
    }
};

int main() {

    float avg;
    const char* menu[] = { "1V1", "1 VS PC", "PC VS PC" };
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

                cout << "You selected 1V1 mode.\n\n";
                Human player1, player2;
                cout << "For First User Choose:\n1-Paper\n2-Rock\n3-Scissors\n";
                player1.MakeChoice();
                system("cls");
                cout << "For Second User Choose:\n1-Paper\n2-Rock\n3-Scissors\n";
                player2.MakeChoice();
                system("cls");
                const char* choices[] = { "Paper", "Rock", "Scissors" };

                cout << "You chose: " << choices[player1.choice] << endl;
                cout << "PC chose: " << choices[player2.choice] << endl;

                if (player1.choice == player2.choice) {
                    cout << "It's a tie!\n";
                }
                else if ((player1.choice == Choice::Rock && player2.choice == Choice::Scissors) ||
                    (player1.choice == Choice::Paper && player2.choice == Choice::Rock) ||
                    (player1.choice == Choice::Scissors && player2.choice == Choice::Paper)) {
                    cout << "Player 1 wins!\n";
                }
                else {
                    cout << "Player 2 wins!\n";
                }
            }

                break;
            case 1: {
                
                cout << "You selected 1 VS PC mode.\n";
                Human player;
                Computer pc;
                cout << "Choose:\n1-Paper\n2-Rock\n3-Scissors\n";
                player.MakeChoice();
                pc.MakeChoice();
                system("cls");
                
                const char* choices[] = { "Paper", "Rock", "Scissors" };

                cout << "You chose: " << choices[player.choice] << endl;
                cout << "PC chose: " << choices[pc.choice] << endl;

                if (player.choice == pc.choice) {
                    cout << "It's a tie!\n";
                }
                else if ((player.choice == Choice::Rock && pc.choice == Choice::Scissors) ||
                    (player.choice == Choice::Paper && pc.choice == Choice::Rock) ||
                    (player.choice == Choice::Scissors && pc.choice == Choice::Paper)) {
                    cout << "You win!\n";
                }
                else {
                    cout << "PC wins!\n";
                }

            }
                break;
            case 2: {
                cout << "You selected PC VS PC mode.\n";
                Computer pc1;
                Computer pc2;
                cout << "Choose:\n1-Paper\n2-Rock\n3-Scissors\n";
                pc1.MakeChoice();
                pc2.MakeChoice();
                system("cls");

                const char* choices[] = { "Paper", "Rock", "Scissors" };

                cout << "PC1 chose: " << choices[pc1.choice] << endl;
                cout << "PC2 chose: " << choices[pc2.choice] << endl;

                if (pc1.choice == pc1.choice) {
                    cout << "It's a tie!\n";
                }
                else if ((pc1.choice == Choice::Rock && pc2.choice == Choice::Scissors) ||
                    (pc1.choice == Choice::Paper && pc2.choice == Choice::Rock) ||
                    (pc1.choice == Choice::Scissors && pc2.choice == Choice::Paper)) {
                    cout << "PC1 win!\n";
                }
                else {
                    cout << "PC2 wins!\n";
                }
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