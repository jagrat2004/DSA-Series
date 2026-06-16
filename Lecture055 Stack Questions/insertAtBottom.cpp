#include<iostream>
#include<stack>
using namespace std;
  
void solve(stack<int>& s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    //recursive call
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack,  int x){
    solve(myStack, x);
    return myStack;
}


int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3); // Stack is now [1, 2, 3] (top = 3)

    int x = 0;
    stack<int> updated = pushAtBottom(s, x);

    // Print updated stack (will print top to bottom)
    while (!updated.empty()) {
        cout << updated.top() << " ";
        updated.pop();
    }
    // Output should be: 3 2 1 0
    return 0;
}
