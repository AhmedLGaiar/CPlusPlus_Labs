#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


class Syllabus {
private:
    string content; 
public:
    Syllabus(const string& content) : content(content) {} 
    void Display() const {
        cout << "Syllabus: " << content << endl;
    }
};

class Professor {
private:
    string name; 
public:
    Professor(const string& name) : name(name) {} 
    string GetName() const { return name; }
    void Display() const {
        cout << "Professor: " << name << endl;
    }
};

class Course {
private:
    string name; 
    Syllabus syllabus; // Composition: A course has a syllabus
    Professor* professor; // Aggregation: A course has a professor

public:
    Course(const string& name, const string& syllabusContent)
        : name(name), syllabus(syllabusContent), professor(nullptr) {
    }

    void SetProfessor(Professor* prof) { 
        professor = prof;
    }

    void Display() const {
        cout << "Course: " << name << endl;
        syllabus.Display(); // Display syllabus information
        if (professor) {
            professor->Display(); // Display professor information if assigned
        }
        else {
            cout << "No professor assigned.\n";
        }
    }

    string GetName() const { return name; }
};

// Class representing a student
class Student {
private:
    string name;
public:
    Student(const string& name) : name(name) {} 

    void Enroll(const Course& course) { 
        cout << name << " has enrolled in " << course.GetName() << endl;
    }

    string GetName() const { return name; } 
};

// Class representing a department
class Department {
private:
    string name; 
    int Dnum; 
    Professor* professors[10]; 
    int professorCount = 0; 
public:
    Department(const string& name, int dnum) : name(name), Dnum(dnum) {}

    void addProfessor(Professor& professor) { 
        if (professorCount < 10) {
            professors[professorCount] = &professor;
            professorCount++;
        }
        else {
            cout << "Department is full, cannot add more professors.\n";
        }
    }

    void Display() const { 
        cout << "Department: " << name << endl;
        for (int i = 0; i < professorCount; ++i) {
            professors[i]->Display(); // Display each professor in the department
        }
    }
};

int main() {

    Student student("Alice");

    Professor professor("Dr. Smith");

    Course course("Computer Science", "Programming and Data Structures");

    // Aggregation
    course.SetProfessor(&professor);

    // Association
    student.Enroll(course);

    course.Display();

    // Aggregation
    Department department("Computer Science Department", 10);
    department.addProfessor(professor);
    department.Display();

    system("pause");

    return 0;
}
