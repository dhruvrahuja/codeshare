#include <iostream>
using namespace std;

class StackArray {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int stack[MAX_SIZE];
    int top;

public:
    StackArray() {
        top = -1; // Initialize the top of the stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        stack[++top] = item;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return stack[top--];
    }
};

int main() {
    StackArray stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    return 0;
}
