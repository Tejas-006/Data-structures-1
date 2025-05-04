#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {} // Constructor
    void enqueue(int value);                  // Add an element to the queue
    void dequeue();                           // Remove an element from the queue
    void peek();                              // Display the front element
    bool isEmpty();                           // Check if the queue is empty
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
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
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
void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode; // Initialize front and rear if queue is empty
    } else {
        rear->next = newNode; // Add new node to the rear
        rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << "Dequeued: " << front->data << endl;
    front = front->next; // Move front to the next node
    delete temp;         // Free memory
    if (front == nullptr) {
        rear = nullptr; // Reset rear if queue becomes empty
    }
}

void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Front element: " << front->data << endl;
}

bool Queue::isEmpty() {
    return front == nullptr; // Queue is empty when front is nullptr
}

/*
Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)
*/