// Refer this code over remaining two

#include <iostream>
using namespace std;


class Queue {
private:
    int* arr;
    int front, rear, MAX_SIZE;

public:
    Queue(int Size) {
        front = rear = -1;
		MAX_SIZE = Size;
		arr = new int[MAX_SIZE];
		
    }

    // Checking the array is empty or not
    bool isEmpty() {
        return (front == -1);
    }

    // Checking the array is full or not
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Adding the element to the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;  // Circular increment
        }
        arr[rear] = element;
    }

    // Deleting the element from the array
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            cout<< "Deleted element "<< arr[front]<< endl;
            front++;  // Circular increment
        }
    }

    // Displaying the elements in the queue
    void display() {
        int i = front;
        while(true){
            cout << " " << arr[i] << " ";
            if(i == rear)
                break;
            i++;
        }
		cout << endl;
    }
};

int main() {
	int size;
	cout<< "Enter size of job queue: ";
	cin>> size;
    Queue job(size);
    int choice, element;

    do {
        cout << "*********************" << endl;
        cout << "1. Add Queue" << endl;
        cout << "2. Delete Queue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;
        cout << "************************" << endl;

        switch (choice) {
            case 1:
                cout << "Enter job to add: ";
                cin >> element;
				if (job.isFull()) {
                    cout << "Queue is full" << endl;
                } else {
                    job.enqueue(element);
                }
                break;

            case 2:
                job.dequeue();
                break;

            case 3:
                if (job.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    job.display();
                }
                break;

            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid Input" << endl;
        }

    } while (choice != 0);

    return 0;
}
