#include <iostream>

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    PriorityQueue() : front(-1), rear(-1) {}

    void enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            std::cout << "Priority Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        int i = rear;

        // Find the correct position for the new element
        while (i >= 0 && value < arr[i]) {
            arr[i + 1] = arr[i];
            i--;
        }

        // Insert the new element
        arr[i + 1] = value;
        rear++;
        
        if (front == -1) {
            front = 0;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Assuming -1 represents an invalid value in the queue
        }

        int value = arr[front];
        front++;

        if (front > rear) {
            // Reset front and rear when the queue becomes empty
            front = rear = -1;
        }

        return value;
    }

    bool isEmpty() const {
        return front == -1;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10);
    pq.enqueue(5);
    pq.enqueue(20);

    while (!pq.isEmpty()) {
        std::cout << pq.dequeue() << " ";
    }

    return 0;
}
