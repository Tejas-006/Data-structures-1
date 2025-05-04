#include <iostream>
#include <string>
#include "stacklist.h" // Include the stack header file

using namespace std;

// Function prototypes
void displayMenu();
bool isBalanced(const string& expression);

int main() {
    int choice;
    string expression;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> expression;
                if (isBalanced(expression)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are NOT balanced.\n";
                }
                break;
            case 2:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Check Balance\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
}

// Function to check if the parentheses are balanced
bool isBalanced(const string& expression) {
    CharStack stack;

    for (char ch : expression) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false; // No matching opening bracket
            }
            char top = stack.pop(); // Pop the top element
            // Check if the popped bracket matches the current closing bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    return stack.isEmpty();
}