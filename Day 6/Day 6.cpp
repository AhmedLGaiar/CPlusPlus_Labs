#include <iostream>
#include <stdexcept>
#include <cstring>
#include <fstream>
using namespace std;

class Employee {
private:
    char name[50];
    int age;

public:
    #pragma region Ctor
        Employee() { name[0] = '\0'; age = 0; }
        Employee(const char* name, int age) {
            strncpy_s(this->name, name, sizeof(this->name) - 1);
            this->name[sizeof(this->name) - 1] = '\0';
            this->age = age;
        }
    #pragma endregion

    #pragma region Getters
        const char* getName() const { return name; }
        int getAge() const { return age; }
    #pragma endregion
    
    #pragma region Setters
        void setName(const char* newName) {
            strncpy_s(name, newName, sizeof(name) - 1);
            name[sizeof(name) - 1] = '\0';
        }
    
        void setAge(int newAge) {
            if (newAge < 18 || newAge > 100) {
                throw invalid_argument("Age must be between 18 and 100.");
            }
            age = newAge;
        }
    #pragma endregion
  
    static void sortEmployees(Employee arr[], int count, bool (*compare)(const Employee&, const Employee&)) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (!compare(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static bool ascendingAge(const Employee& a, const Employee& b) {
        return a.age < b.age;
    }

    static bool descendingAge(const Employee& a, const Employee& b) {
        return a.age > b.age;
    }
    #pragma region Find 
    static Employee findByName(Employee arr[], int count, const char* searchName) {
        for (int i = 0; i < count; i++) {
            if (strcmp(arr[i].name, searchName) == 0) {
                return arr[i];
            }
        }
        throw runtime_error(string("No employee found with name: ") + searchName);
    }

    static Employee findByAge(Employee arr[], int count, int searchAge) {
        for (int i = 0; i < count; i++) {
            if (arr[i].age == searchAge) {
                return arr[i];
            }
        }
        throw runtime_error("No employee found with the specified age.");
    }
    #pragma endregion

    static void saveToFile(Employee arr[], int count, const char* fileName) {
        ofstream file(fileName);
        if (!file) {
            cerr << "Failed to open file for writing!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            file << arr[i].name << " " << arr[i].age << "\n";
        }
        file.close();
        cout << "Employee data saved successfully to " << fileName << endl;
    }
};

int main() {
    int count;

    do {
        cout << "Enter number of employees (at least 1): ";
        cin >> count;
        if (count < 1) {
            cout << "Invalid input. Please enter a valid number!\n";
        }
    } while (count < 1);
    cin.ignore();

    Employee* empList = new Employee[count];

    for (int i = 0; i < count; i++) {
        char name[50];
        int age;

        do {
            cout << "Enter name of employee " << i + 1 << ": ";
            cin >> name;
        } while (strlen(name) == 0);

        do {
            cout << "Enter age of " << name << ": ";
            cin >> age;
            if (age < 18 || age > 100) {
                cout << "Invalid age! Please enter an age between 18 and 100.\n";
            }
        } while (age < 18 || age > 100);
        cin.ignore();

        empList[i] = Employee(name, age);
    }

    cout << "\nSorting employees by age (ascending):\n";
    Employee::sortEmployees(empList, count, Employee::ascendingAge);
    for (int i = 0; i < count; i++) {
        cout << empList[i].getName() << " - " << empList[i].getAge() << endl;
    }

    cout << "\nSorting employees by age (descending):\n";
    Employee::sortEmployees(empList, count, Employee::descendingAge);
    for (int i = 0; i < count; i++) {
        cout << empList[i].getName() << " - " << empList[i].getAge() << endl;
    }

    try {
        Employee e = Employee::findByName(empList, count, "ENG Ahmed ELGaiar");
        cout << "\nEmployee found: " << e.getName() << " - " << e.getAge() << endl;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }

    try {
        Employee e = Employee::findByAge(empList, count, 23);
        cout << "Employee found: " << e.getName() << " - " << e.getAge() << endl;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }

    Employee::saveToFile(empList, count, "ELGaiarCompany_data.txt");

    delete[] empList;

    return 0;
}
