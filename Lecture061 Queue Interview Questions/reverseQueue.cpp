#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Function to reverse a queue using a stack
queue<int> rev(queue<int> q) {
    stack<int> s;

    // Step 1: Push all elements from the queue to the stack
    while (!q.empty()) {
        int element = q.front();  // Get the front element of the queue
        q.pop();                  // Remove it from the queue
        s.push(element);          // Push it into the stack
    }

    // Step 2: Push all elements from the stack back to the queue
    while (!s.empty()) {
        int element = s.top();    // Get the top element from the stack
        s.pop();                  // Remove it from the stack
        q.push(element);          // Push it back into the queue
    }

    return q;
}

int main() {
    queue<int> q;

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // Print original queue
    cout << "Original queue: ";
    queue<int> temp = q; // Temporary copy for displaying without modifying original
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    q = rev(q);

    // Print reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
