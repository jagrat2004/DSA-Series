#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int>& stack, int num){
    if(stack.empty() || stack.top() < num){
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortInsert(stack, num);
    stack.push(n); // Fix: restore previous element
}

void sortStack(stack<int>& stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack, num);
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
