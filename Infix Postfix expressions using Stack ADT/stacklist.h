#ifndef CHARSTACK_H
#define CHARSTACK_H

#include <iostream>
#include <cstdlib> // Required for malloc

using namespace std;

// Stack class definition
class CharStack {
private:
    struct Node { // Node structure for the linked list
        char data;
        Node* next;
    };
    Node* top; // Pointer to the top of the stack

public:
    CharStack();  // Constructor
    ~CharStack(); // Destructor

    void push(char value); // Push function
    char pop(); // Pop function
    char peek(); // Peek function
    bool isEmpty(); // Check if the stack is empty
};

// Constructor initializes the stack
CharStack::CharStack() {
    top = nullptr; // Stack is initially empty
}

// Destructor: Frees all dynamically allocated nodes
CharStack::~CharStack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        free(temp); // Deallocate memory
    }
    cout << "Stack destroyed!\n";
}

// Push function: Adds an element to the stack
void CharStack::push(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        cerr << "Memory allocation failed!\n";
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed: " << value << endl;
}

// Pop function: Removes and returns the top element
char CharStack::pop() {
    if (!top) {
        cerr << "Stack underflow! Cannot pop from an empty stack.\n";
        return '\0'; // Return null character when stack is empty
    }
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Peek function: Returns the top element without removing it
char CharStack::peek() {
    if (!top) {
        cerr << "Stack is empty! No element to peek.\n";
        return '\0'; // Return null character when stack is empty
    }
    return top->data;
}

// Check if the stack is empty
bool CharStack::isEmpty() {
    return (top == nullptr);
}

#endif // CHARSTACK_H