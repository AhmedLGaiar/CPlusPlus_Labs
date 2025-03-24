#include <iostream>
#include <stdexcept>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int age;

public:
    Employee() : name(""), age(0) {}
    Employee(const string& name, int age) : name(name), age(age) {}

    const string& getName() const { return name; }
    int getAge() const { return age; }

    void setName(const string& newName) { name = newName; }

    void setAge(int newAge) {
        if (newAge < 18 || newAge > 100) {
            throw invalid_argument("Age must be between 18 and 100.");
        }
        age = newAge;
    }

    static void sortEmployees(vector<Employee>& employees, bool (*compare)(const Employee&, const Employee&)) {
        sort(employees.begin(), employees.end(), compare);
    }

    static bool ascendingAge(const Employee& a, const Employee& b) {
        return a.age < b.age;
    }

    static bool descendingAge(const Employee& a, const Employee& b) {
        return a.age > b.age;
    }

    static Employee findByName(const vector<Employee>& employees, const string& searchName) {
        auto it = find_if(employees.begin(), employees.end(), [&](const Employee& emp) { return emp.getName() == searchName; });
        if (it != employees.end()) {
            return *it;
        }
        throw runtime_error("No employee found with name: " + searchName);
    }

    static Employee findByAge(const vector<Employee>& employees, int searchAge) {
        auto it = find_if(employees.begin(), employees.end(), [&](const Employee& emp) { return emp.getAge() == searchAge; });
        if (it != employees.end()) {
            return *it;
        }
        throw runtime_error("No employee found with the specified age.");
    }

    static void saveToFile(const vector<Employee>& employees, const string& fileName) {
        ofstream file(fileName);
        if (!file) {
            cerr << "Failed to open file for writing!" << endl;
            return;
        }

        for (const auto& emp : employees) {
            file << emp.name << " " << emp.age << "\n";
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

    vector<Employee> empList;

    for (int i = 0; i < count; i++) {
        string name;
        int age;

        cout << "Enter name of employee " << i + 1 << ": ";
        getline(cin, name);

        do {
            cout << "Enter age of " << name << ": ";
            cin >> age;
            if (age < 18 || age > 100) {
                cout << "Invalid age! Please enter an age between 18 and 100.\n";
            }
        } while (age < 18 || age > 100);
        cin.ignore();

        empList.emplace_back(name, age);
    }

    cout << "\nSorting employees by age (ascending):\n";
    Employee::sortEmployees(empList, Employee::ascendingAge);
    for (const auto& emp : empList) {
        cout << emp.getName() << " - " << emp.getAge() << endl;
    }

    cout << "\nSorting employees by age (descending):\n";
    Employee::sortEmployees(empList, Employee::descendingAge);
    for (const auto& emp : empList) {
        cout << emp.getName() << " - " << emp.getAge() << endl;
    }

    try {
        Employee e = Employee::findByName(empList, "ENG Ahmed ELGaiar");
        cout << "\nEmployee found: " << e.getName() << " - " << e.getAge() << endl;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }

    try {
        Employee e = Employee::findByAge(empList, 23);
        cout << "Employee found: " << e.getName() << " - " << e.getAge() << endl;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }

    Employee::saveToFile(empList, "ELGaiarCompany_data.txt");

    return 0;
}