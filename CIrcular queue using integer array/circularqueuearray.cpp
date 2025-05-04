#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int arr[5]; // Array of size 5

public:
    CircularQueue() : front(-1), rear(-1) {} // Constructor
    bool isFull();                           // Check if the queue is full
    bool isEmpty();                          // Check if the queue is empty
    void enqueue(int value);                // Add an element to the queue
    void dequeue();                         // Remove an element from the queue
    void peek();                            // Display the front element
};

// Main function
int main() {
    CircularQueue cq;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!cq.isFull()) {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    cq.enqueue(value);
                } else {
                    cout << "Queue is full!" << endl;
                }
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Function definitions
bool CircularQueue::isFull() {
    return (rear + 1) % 5 == front; // Circular condition for full queue
}

bool CircularQueue::isEmpty() {
    return front == -1; // Queue is empty when front is -1
}

void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front if queue is empty
    }
    rear = (rear + 1) % 5; // Circular increment
    arr[rear] = value;
    cout << "Enqueued: " << value << endl;
}

void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1; // Reset queue if it becomes empty
    } else {
        front = (front + 1) % 5; // Circular increment
    }
}

void CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << arr[front] << endl;
}

/*
Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
*/