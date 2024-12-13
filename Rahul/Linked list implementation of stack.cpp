#include <iostream>

// Node structure for the stack
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed: " << value << std::endl;
    }

    // Pop the top element from the stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            std::cout << "Popped: " << temp->data << std::endl;
            delete temp;
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Display the elements of the stack
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            Node* current = top;
            std::cout << "Stack elements: ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.display();

    myStack.pop();
    myStack.pop();

    myStack.display();

    myStack.pop();  // Trying to pop from an empty stack

    return 0;
}
