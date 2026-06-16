#include<iostream>       // For input-output operations
#include<queue>          // For using queue STL
#include<stack>          // For using stack STL
using namespace std;

// Function to reverse the first k elements of the queue
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s; // Stack to reverse elements

    // Step 1: Push first k elements from queue to stack
    for (int i = 0; i < k; i++) {
        int val = q.front();  // Get front element of queue
        q.pop();              // Remove it from queue
        s.push(val);          // Push it onto the stack
    }

    // Step 2: Enqueue back the stack elements (they will be in reversed order)
    while (!s.empty()) {
        int val = s.top();    // Get the top element of stack
        s.pop();              // Pop it from stack
        q.push(val);          // Push it back into the queue
    }

    // Step 3: Move the remaining (n-k) elements from front to back of the queue
    int t = q.size() - k;     // Number of elements to rotate
    while (t--) {
        int val = q.front();  // Get front element
        q.pop();              // Remove it from front
        q.push(val);          // Push it to the back
    }

    return q; // Return the modified queue
}

int main() {
    queue<int> q; // Declare a queue

    // Sample input elements pushed into queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    int k = 3; // Number of elements to reverse from front

    // Display the original queue
    cout << "Original queue: ";
    queue<int> temp = q;          // Create a copy of the queue for printing
    while (!temp.empty()) {       // Loop until the copy is empty
        cout << temp.front() << " "; // Print front element
        temp.pop();               // Remove front element
    }
    cout << endl;

    // Modify the queue by reversing first k elements
    q = modifyQueue(q, k);

    // Display the modified queue
    cout << "Modified queue: ";
    while (!q.empty()) {         // Loop through modified queue
        cout << q.front() << " "; // Print front element
        q.pop();                 // Remove front element
    }

    return 0; // Exit program
}
