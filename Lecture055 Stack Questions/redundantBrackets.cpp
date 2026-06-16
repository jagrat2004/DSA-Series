#include<iostream>            // Includes input-output stream library
#include<stack>               // Includes stack data structure
using namespace std;          // Uses the standard namespace

// Function to check if the expression contains redundant parentheses
bool isRedundant(string &s) {
    stack<char> st;           // Stack to store characters (operators and brackets)

    // Iterate over each character in the string
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];       // Current character

        // If it's an opening bracket or an operator, push to stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        // If it's a closing bracket
        else if(ch == ')') {
            bool isOperatorFound = false; // Flag to track if any operator exists between brackets

            // Pop all elements until opening bracket '(' is found
            while(!st.empty() && st.top() != '(') {
                char top = st.top();       // Top of the stack

                // If an operator is found, set the flag to true
                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    isOperatorFound = true;
                }

                st.pop();                  // Pop the top element
            }

            // Pop the opening bracket '('
            if(!st.empty()) st.pop();

            // If no operator found between '(', ')', it's redundant
            if(!isOperatorFound) {
                return true;
            }
        }
    }

    return false;  // No redundant brackets found
}

int main() {
    string expr1 = "((a+b))";  // Expression with redundant parentheses
    string expr2 = "(a+(b))";  // Expression with inner redundant parentheses
    string expr3 = "(a+b)";    // Valid expression, no redundant parentheses

    // Print whether each expression has redundant brackets or not
    cout << expr1 << " --> " << (isRedundant(expr1) ? "Redundant" : "Not Redundant") << endl;
    cout << expr2 << " --> " << (isRedundant(expr2) ? "Redundant" : "Not Redundant") << endl;
    cout << expr3 << " --> " << (isRedundant(expr3) ? "Redundant" : "Not Redundant") << endl;

    return 0;  // End of program
}
