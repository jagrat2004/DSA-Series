#include<iostream>
#include<string>
#include<stack>
using namespace std;

int findMinimumCost(string str) {
    // Check for odd length
    if(str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;

    // Remove balanced pairs
    for(char ch : str) {
        if(ch == '{') {
            s.push(ch);
        } else {
            if(!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(ch);
            }
        }
    }

    // Count unbalanced brackets
    int open = 0, close = 0;
    while(!s.empty()) {
        if(s.top() == '{') open++;
        else close++;
        s.pop();
    }

    // Minimum reversals = ceil(open/2) + ceil(close/2)
    int ans = (open + 1)/2 + (close + 1)/2;
    return ans;
}

int main() {
    string s;
    cout << "Enter a bracket string (consisting of only '{' and '}'): ";
    cin >> s;

    int result = findMinimumCost(s);

    if (result == -1) {
        cout << "The string can't be balanced (odd length)." << endl;
    } else {
        cout << "Minimum reversals needed: " << result << endl;
    }

    return 0;
}
