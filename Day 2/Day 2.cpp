#include <iostream>
using namespace std;

class Stack {
private:
    int maxSize;
    int top;
    int* array;

public:
    
    Stack(int size) {
        maxSize = size;
        top = -1;
        array = new int[maxSize];
    }

    // Copy assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] array;
            maxSize = other.maxSize;
            top = other.top;
            array = new int[maxSize];
            for (int i = 0; i <= top; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

   
    ~Stack() {
        delete[] array;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        array[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return -1;
        }
        return array[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    bool isFull() {
        return (top >= maxSize - 1);
    }
};

class Complex {
public:
    float real;
    float imag;

    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    Complex operator--(int) {
        Complex temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }

    Complex& operator=(const Complex& c) {
        if (this != &c) {
            real = c.real;
            imag = c.imag;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }

    void Display() const {
        cout << *this << endl;
    }
};

class MyArray {
private:
    int* arr;
    int size;

public:
    MyArray(int size) : size(size) {
        arr = new int[size];
    }

    MyArray() : MyArray(10) {} // Default size 10

    ~MyArray() {
        delete[] arr;
    }

    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        else {
            cout << "Index out of range";
            exit(1);
        }
    }

    const int& operator[](int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        else {
            cout << "Index out of range";
            exit(1);
        }
    }
};


int main() {

    MyArray arr(5);
    arr[0] = 10;
    cout << "arr[0]: " << arr[0] << endl;

    cout << "*******************************************" << endl;

    Stack stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack stack2(5);
    stack2 = stack1;

    cout << "Stack assignment completed." << endl;

    cout << "*******************************************" << endl;

     Complex c1(3.5, 2.5), c2(1.5, -4.0);
    cout << "First Complex: " << c1 << endl;
    cout << "Second Complex: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex diff = c1 - c2;
    cout << "Difference: " << diff << endl;

    cout << "Incrementing c1: " << ++c1 << endl;
    cout << "Post-incrementing c1: " << c1++ << endl;
    cout << "After post-increment, c1: " << c1 << endl;

    cout << "Decrementing c2: " << --c2 << endl;
    cout << "Post-decrementing c2: " << c2-- << endl;
    cout << "After post-decrement, c2: " << c2 << endl;

    cout << "Checking equality (c1 == c2): " << (c1 == c2 ? "True" : "False") << endl;

    Complex c3;
    cout << "Enter a new complex number:" << endl;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    Complex staticArray[3] = { {1.2, 3.4}, {5.6, 7.8}, {9.0, -1.2} };
    cout << "Static Array of Complex Numbers:" << endl;
    for (const auto& c : staticArray) {
        c.Display();
    }

    int size = 3;
    Complex* dynamicArray = new Complex[size] { {2.3, 4.5}, {6.7, -8.9}, {1.0, 2.0} };
    cout << "\nDynamic Array of Complex Numbers:" << endl;
    for (int i = 0; i < size; ++i) {
        dynamicArray[i].Display();
    }
    delete[] dynamicArray;


    return 0;
}
