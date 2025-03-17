#include <iostream>
using namespace std;

class Stack {
private:
    int maxSize;  
    int top;      
    int* array;   

public:
    // Constructor
    Stack(int size) {
        maxSize = size;
        top = -1;         
        array = new int[maxSize];  
    }

    // Destructor
    ~Stack() {
        delete[] array;    
    }

    
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        array[++top] = value;
        cout << value << " pushed to stack" << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return -1;  
        }
        return array[top--];
    }

    // Peek at the top element without removing it
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

/*******************************************************************/

struct Complex {
    float real;      
    float imag;     

    // Constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

  
    void Display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    
    Complex Add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    
    Complex Subtract(Complex c) {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
};


int main() {

    Stack stack(5);  

    // Test push
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Test peek
    cout << "Top element: " << stack.peek() << endl;

    // Test pop
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    // Test empty stack
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test overflow
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);  
    stack.push(8);  // overflow

    cout << "*****************************************************\n";

    Complex c1(3.5, 2.5);    
    Complex c2(1.5, -4.0);   

    cout << "First complex number: ";
    c1.Display();
    cout << endl;

    cout << "Second complex number: ";
    c2.Display();
    cout << endl;

    Complex sum = c1.Add(c2);
    cout << "Sum: ";
    sum.Display();
    cout << endl;

    Complex diff = c1.Subtract(c2);
    cout << "Difference: ";
    diff.Display();
    cout << endl;


    return 0;
}