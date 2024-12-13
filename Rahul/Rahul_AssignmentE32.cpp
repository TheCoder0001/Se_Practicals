#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int front, rear, capacity;
    int *orders;

public:
    PizzaParlor(int M) {
        front = rear = -1;
        capacity = M;
        orders = new int[capacity];
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void placeOrder(int order) {
        if (isFull()) {
            cout << "Order cannot be placed. Pizza parlor is full." << endl;
			
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % capacity;
        orders[rear] = order;
    }

    int serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve. Pizza parlor is empty." << endl;
            return -1;
        }
        int servedOrder = orders[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        return servedOrder;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders to display. Pizza parlor is empty." << endl;
        }
        int i = front;
        cout << "Orders in the pizza parlor: ";
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int M, choice, order;
    cout << "Enter the maximum number of orders (M): ";
    cin >> M;
    PizzaParlor pizzaParlor(M);

    do {
        cout << "\nPizza Parlor Simulation\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (pizzaParlor.isFull()) {
                    cout << "Order cannot be placed. Pizza parlor is full." << endl;
                } else {
                    cout << "Enter the order number: ";
                    cin >> order;
                    pizzaParlor.placeOrder(order);
                }
                break;
            case 2:
                order = pizzaParlor.serveOrder();
                if (order != -1) {
                    cout << "Served Order: " << order << endl;
                }
                break;
            case 3:
                pizzaParlor.displayOrders();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
