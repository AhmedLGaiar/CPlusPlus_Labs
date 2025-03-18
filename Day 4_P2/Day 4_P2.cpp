#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

void gotoxy1(int x, int y);
void SetColorAndBackground(int ForgC, int BackC);

class Users {
private:
    string username;
    string password;
    bool isActive;
public:
    Users() : username(""), password(""), isActive(false) {}

    bool registerUser(string user, string pass) {
        if (username.empty() && !user.empty() && !pass.empty()) {
            username = user;
            password = pass;
            isActive = true;
            return true;
        }
        return false;
    }

    bool login(string user, string pass) {
        if (isActive && username == user && password == pass) {
            return true;
        }
        return false;
    }

    bool isEmpty() const { return !isActive; }
    string getUsername() const { return username; }
};

class Student {
private:
    Users user;
    string courses[3];
    int courseCount;
    static const string availableCourses[5];

public:
    Student() : courseCount(0) {
        for (int i = 0; i < 3; i++) {
            courses[i] = "";
        }
    }

    bool setUser(Users u) {
        if (user.isEmpty()) {
            user = u;
            return true;
        }
        return false;
    }

    bool login(string username, string password) {
        return user.login(username, password);
    }

    string getUsername() const {
        return user.getUsername();
    }

    bool enrollCourse(int courseIndex) {
        if (courseIndex < 0 || courseIndex >= 5) return false;
        if (courseCount >= 3) return false;

        string selectedCourse = availableCourses[courseIndex];

        // Check for duplicate course
        for (int i = 0; i < courseCount; i++) {
            if (courses[i] == selectedCourse) return false;
        }

        courses[courseCount] = selectedCourse;
        courseCount++;
        return true;
    }

    void displayCourses(int x, int y) {
        gotoxy1(x, y);
        cout << "Enrolled Courses for " << user.getUsername() << ":";
        for (int i = 0; i < courseCount; i++) {
            gotoxy1(x, y + i + 1);
            cout << i + 1 << ". " << courses[i];
        }
        if (courseCount == 0) {
            gotoxy1(x, y + 1);
            cout << "No courses enrolled yet";
        }
    }

    static void displayAvailableCourses(int x, int y) {
        gotoxy1(x, y);
        cout << "Available Courses:";
        for (int i = 0; i < 5; i++) {
            gotoxy1(x, y + i + 1);
            cout << i + 1 << ". " << availableCourses[i];
        }
    }

    bool isEmpty() const { return user.isEmpty(); }
};

// Define static member
const string Student::availableCourses[5] = {
    "C++",
    "Csharp",
    "C",
    "OOP",
    "Java"
};

const int MAX_USERS = 100;
Student studentList[MAX_USERS];

int findEmptySlot() {
    for (int i = 0; i < MAX_USERS; i++) {
        if (studentList[i].isEmpty()) return i;
    }
    return -1;
}

int findUser(string username) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (!studentList[i].isEmpty() && studentList[i].getUsername() == username) {
            return i;
        }
    }
    return -1;
}

void courseMenu(int studentIndex) {
    bool running = true;
    while (running) {
        system("cls");
        gotoxy1(40, 2);
        cout << "Course Management";

        Student::displayAvailableCourses(40, 4);
        studentList[studentIndex].displayCourses(40, 11);

        gotoxy1(40, 16);
        cout << "Enter course number to enroll (0 to exit): ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            running = false;
        }
        else if (choice >= 1 && choice <= 5) {
            if (studentList[studentIndex].enrollCourse(choice - 1)) {
                gotoxy1(40, 18);
                SetColorAndBackground(10, 0);
                cout << "Course enrolled successfully!";
            }
            else {
                gotoxy1(40, 18);
                SetColorAndBackground(12, 0);
                cout << "Enrollment failed! (Max courses reached or duplicate)";
            }
            Sleep(1500);
        }
    }
}

int main() {
    const char* menu[] = { "Log in", "Register", "Exit" };
    bool isRunning = true;
    int selected = 0;

    do {
        gotoxy1(50, 2);
        SetColorAndBackground(14, 0);
        cout << "Student Management System";

        for (int i = 0; i < 3; i++) {
            gotoxy1(50, 6 + i * 2);
            if (i == selected) {
                SetColorAndBackground(15, 1);
            }
            else {
                SetColorAndBackground(15, 0);
            }
            cout << menu[i] << "        ";
        }

        char key = _getch();
        switch (key) {
        case 72: // Up arrow
            --selected;
            if (selected < 0) selected = 2;
            break;
        case 80: // Down arrow
            ++selected;
            if (selected > 2) selected = 0;
            break;
        case 13: // Enter
            SetColorAndBackground(15, 0);
            system("cls");

            switch (selected) {
            case 0: { // Login
                string user, pass;
                gotoxy1(40, 10); cout << "Username: ";
                getline(cin, user);
                gotoxy1(40, 11); cout << "Password: ";
                getline(cin, pass);

                int userIndex = findUser(user);
                if (userIndex != -1 && studentList[userIndex].login(user, pass)) {
                    gotoxy1(40, 13);
                    SetColorAndBackground(10, 0);
                    cout << "Login successful! Welcome, " << user;
                    Sleep(1000);
                    courseMenu(userIndex);
                }
                else {
                    gotoxy1(40, 13);
                    SetColorAndBackground(12, 0);
                    cout << "Login failed! Invalid credentials";
                }
                break;
            }
            case 1: { // Register
                string user, pass;
                gotoxy1(40, 10); cout << "New Username: ";
                getline(cin, user);

                if (findUser(user) != -1) {
                    gotoxy1(40, 12);
                    SetColorAndBackground(12, 0);
                    cout << "Username already exists!";
                    break;
                }

                gotoxy1(40, 11); cout << "New Password: ";
                getline(cin, pass);

                int slot = findEmptySlot();
                if (slot != -1) {
                    Users newUser;
                    if (newUser.registerUser(user, pass) && studentList[slot].setUser(newUser)) {
                        gotoxy1(40, 13);
                        SetColorAndBackground(10, 0);
                        cout << "Registration successful!";
                    }
                }
                else {
                    gotoxy1(40, 13);
                    SetColorAndBackground(12, 0);
                    cout << "Registration failed! System full";
                }
                break;
            }
            case 2: { // Exit
                gotoxy1(40, 10);
                SetColorAndBackground(14, 0);
                cout << "Goodbye!";
                Sleep(1000);
                isRunning = false;
                break;
            }
            }

            if (selected != 2) {
                gotoxy1(40, 15);
                SetColorAndBackground(15, 0);
                cout << "Press any key to continue...";
                _getch();
                system("cls");
            }
            break;
        case 27: // Escape
            isRunning = false;
            break;
        }
    } while (isRunning);

    return 0;
}

void gotoxy1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColorAndBackground(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}