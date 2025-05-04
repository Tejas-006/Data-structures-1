#include <iostream>
#include <string>
#include <cctype> // For isdigit, isalpha
#include "stacklist.h" // Include the stack header file

using namespace std;

// Function prototypes
void displayMenu();
string infixToPostfix(const string& infix);
int evaluatePostfix(const string& postfix);
int precedence(char op);
bool isOperator(char ch);

int main() {
    string infix, postfix;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            case 3:
                cout << "Result: " << evaluatePostfix(postfix) << endl;
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Get Infix\n";
    cout << "2. Convert Infix to Postfix\n";
    cout << "3. Evaluate Postfix\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
            ch == '<' || ch == '>' || ch == '=' || ch == '!' || ch == '&' ||
            ch == '|' || ch == '^' || ch == '~' || ch == '?' || ch == ':');
}

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '^') return 7; // Highest precedence
    if (op == '*' || op == '/' || op == '%') return 6;
    if (op == '+' || op == '-') return 5;
    if (op == '<' || op == '>' || op == '=' || op == '!') return 4;
    if (op == '&') return 3;
    if (op == '|') return 2;
    if (op == '?') return 1; // Ternary operator
    return 0; // Default for non-operators
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    CharStack stack;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) { // Operand
            postfix += ch;
        } else if (ch == '(') { // Left parenthesis
            stack.push(ch);
        } else if (ch == ')') { // Right parenthesis
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else if (isOperator(ch)) { // Operator
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    CharStack stack;

    for (char ch : postfix) {
        if (isalnum(ch)) { // Operand
            stack.push(ch - '0'); // Convert char to int
        } else if (isOperator(ch)) { // Operator
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '%': result = operand1 % operand2; break;
                case '<': result = operand1 < operand2; break;
                case '>': result = operand1 > operand2; break;
                case '=': result = (operand1 == operand2); break;
                case '!': result = (operand1 != operand2); break;
                case '&': result = operand1 & operand2; break;
                case '|': result = operand1 | operand2; break;
                case '^': result = operand1 ^ operand2; break;
                default: result = 0; break;
            }

            stack.push(result);
        }
    }

    return stack.pop();
}