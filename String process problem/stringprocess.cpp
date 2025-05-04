#include <iostream>
#include <stack>
using namespace std;

string processString(const string& input) {
    stack<char> st;
    for (char ch : input) {
        if (ch == '+') {
            if (!st.empty()) {
                st.pop(); // Remove the immediate left non-'+' symbol
            }
        } else {
            st.push(ch); // Push non-'+' symbols onto the stack
        }
    }

    string result;
    while (!st.empty()) {
        result = st.top() + result; // Build the result string
        st.pop();
    }
    return result;
}

// Main function
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = processString(input);
    cout << "Processed string: " << output << endl;

    return 0;
}

/*
Time Complexity: O(n), where n is the length of the input string.
*/