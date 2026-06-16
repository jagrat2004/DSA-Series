#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& stack, int element){
    //base case
    if(stack.empty()){
        stack.push(element);
        return;
    }
    int num = stack.top();
    stack.pop();

    solve(stack,element);
    stack.push(num);
}

void reverseStack(stack<int>& stack){
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);
    solve(stack, num);
}

int main(){
    stack<int> s;

    // Pushing elements to the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);  // Stack top is 4, bottom is 1

    reverseStack(s);

    // Now print reversed stack: should print 1 2 3 4 (top to bottom)
    cout << "Reversed Stack:" << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
