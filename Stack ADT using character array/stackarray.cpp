#include <iostream>

using namespace std;

#define MAX 5 // Maximum size of the stack

// Stack class definition
class CharStack {
private:
    char arr[MAX]; // Array to store stack elements
    int top; // Index of the top element

public:
    CharStack(); // Constructor
    void push(char value); // Push function
    char pop(); // Pop function
    char peek(); // Peek function
};

// Main function (placed before function definitions)
int main() {
    CharStack s;
    int choice;
    char value;

    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != '\0') // Ensures output only when pop is successful
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                value = s.peek();
                if (value != '\0') // Ensures output only when peek is successful
                    cout << "Top element: " << value << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Constructor initializes the stack
CharStack::CharStack() {
    top = -1; // Stack is initially empty
}

// Push function: Adds an element to the stack
void CharStack::push(char value) {
    if (top >= MAX - 1) { // Stack overflow check
        cerr << "Stack overflow! Cannot push more elements.\n";
        return;
    }
    arr[++top] = value; // Increment top and store the value
    cout << "Pushed: " << value << endl;
}

// Pop function: Removes and returns the top element
char CharStack::pop() {
    if (top == -1) { // Stack underflow check
        cerr << "Stack underflow! Cannot pop from an empty stack.\n";
        return '\0'; // Return null character when stack is empty
    }
    return arr[top--]; // Return the top element and decrease top
}

// Peek function: Returns the top element without removing it
char CharStack::peek() {
    if (top == -1) { // Check if stack is empty
        cerr << "Stack is empty! No element to peek.\n";
        return '\0'; // Return null character when stack is empty
    }
    return arr[top]; // Return top element without modifying stack
}
