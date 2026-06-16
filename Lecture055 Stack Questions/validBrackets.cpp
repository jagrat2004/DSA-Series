#include<iostream>
#include<stack>
using namespace std;

bool validParentheses(string exp) {
    stack<char> s;

    for(int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // Push all opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            // For closing brackets
            if(!s.empty()) {
                char top = s.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {
                    s.pop(); // Valid pair
                } else {
                    return false; // Mismatched pair
                }
            } else {
                return false; // Closing bracket with empty stack
            }
        }
    }

    // After loop, if stack is empty → valid
    return s.empty();
}
int main() {
    string exp = "{[()]}"; // Try different strings

    if(validParentheses(exp)) {
        cout << "Valid Expression" << endl;
    } else {
        cout << "Invalid Expression" << endl;
    }

    return 0;
}
