#include <iostream>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 5; // Maximum size of the stack
    int arr[MAX_SIZE];
    int top; // Index of the top element

public:
    // Constructor
    Stack() : top(-1) {}

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (!isEmpty()) {
            cout << "Popped: " << arr[top--] << endl;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Peek at the top element without removing it
    void peek() const {
        if (!isEmpty()) {
            cout << "Top element: " << arr[top] << endl;
        } else {
            cout << "Stack is empty. Cannot peek." << endl;
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.peek();

    myStack.pop();
    myStack.pop();

    myStack.peek();

    myStack.pop();  // Trying to pop from an empty stack

    return 0;
}
