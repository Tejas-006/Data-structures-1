#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int arr[5]; // Array of size 5

public:
    Queue() : front(-1), rear(-1) {} // Constructor to initialize front and rear
    bool isFull();                   // Check if the queue is full
    bool isEmpty();                  // Check if the queue is empty
    void enqueue(int value);         // Add an element to the queue
    void dequeue();                  // Remove an element from the queue
    void peek();                     // Display the front element
};

// Main function
int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!q.isFull()) {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                } else {
                    cout << "Queue is full!" << endl;
                }
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
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
bool Queue::isFull() {
    return rear == 4; // Queue is full when rear reaches the last index
}

bool Queue::isEmpty() {
    return front == -1; // Queue is empty when front is -1
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front if queue is empty
    }
    arr[++rear] = value; // Increment rear and add the value
    cout << "Enqueued: " << value << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear) {
        front = rear = -1; // Reset queue if it becomes empty
    } else {
        front++; // Move front to the next element
    }
}

void Queue::peek() {
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