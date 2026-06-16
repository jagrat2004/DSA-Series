#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& inputStack, int count, int size){
    //base case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    //recursive call
    solve(inputStack, count+1, size);
    inputStack.push(num);
}
void deletemiddle(stack<int>& inputStack, int n){
    int count = 0;
    solve(inputStack, count, n);
}

int main(){
    stack<int> s;
    
    // Push elements to the stack: [1 (bottom), 2, 3, 4, 5 (top)]
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int n = s.size();  // Total number of elements

    deletemiddle(s, n);

    // Output the updated stack after middle deletion
    cout << "Stack after deleting middle element:" << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
