#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


template <typename T>
class DataContainer {
protected:
    T* data;
    int size;

public:
   
    DataContainer(int s) : size(s) {
        data = new T[size];
    }

    // Copy Constructor
    DataContainer(const DataContainer& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    
    DataContainer& operator=(const DataContainer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

   
    virtual ~DataContainer() {
        delete[] data;
    }

    
    int getSize() const {
        return size;
    }
};


template <typename T>
class Stack : public DataContainer<T> {
private:
    int top;

public:
    Stack(int s) : DataContainer<T>(s), top(-1) {}

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        this->data[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return T();
        }
        return this->data[top--];
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return this->data[top];
    }

    bool isEmpty() const {
        return (top < 0);
    }

    bool isFull() const {
        return (top >= this->size - 1);
    }
};

template <typename T>
class MyArray : public DataContainer<T> {
public:
    MyArray(int s) : DataContainer<T>(s) {}

    T& operator[](int index) {
        if (index >= 0 && index < this->size) {
            return this->data[index];
        }
        else {
            cout << "Index out of range" << endl;
            exit(1);
        }
    }
};


//To Move Cursor to X and Y
void gotoxy1(int x, int y);

//To Change Color
void SetColorAndBackground(int ForgC, int BackC);

template <typename T>
void Swap(T& a, T& b);

int main() {

    int x = 10, y = 20;
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;

    Swap(x, y);

    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    double a = 1.5, b = 2.5;
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;

    Swap(a, b);

    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    cout << "*******************************************************" << endl;


    // Stack of integers
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    cout << "Popped from intStack: " << intStack.pop() << endl;

    // Stack of doubles
    Stack<double> doubleStack(5);
    doubleStack.push(1.5);
    doubleStack.push(2.5);
    cout << "Popped from doubleStack: " << doubleStack.pop() << endl;

    // Array of strings
    MyArray<string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World !";
    cout << "strArray[1]: " << strArray[1] << endl;

    return 0;
}

template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
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