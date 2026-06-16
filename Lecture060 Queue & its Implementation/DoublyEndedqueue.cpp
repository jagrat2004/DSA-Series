#include<iostream>         // Include input-output stream library
#include<stack>            // Include stack library (not used in this code)
#include<queue>            // Include queue library (not used in this code)

using namespace std;

// Custom class for implementing circular deque
class MyDeque {
    int *arr;              // Pointer to the array that holds deque elements
    int front;             // Index of the front element
    int rear;              // Index of the rear element
    int size;              // Maximum size of the deque

public:
    // Constructor to initialize the deque with given size
    MyDeque(int n) {
        size = n;
        arr = new int[n];  // Allocate memory for array
        front = -1;        // Initialize front and rear as -1 to indicate empty deque
        rear = -1;
    }

    // Insert element at the front
    bool pushfront(int x) {
        // Check for deque overflow
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return false;
        } 
        // If deque is empty
        else if (front == -1) {
            front = rear = 0;
        } 
        // Wrap around if front is at first position
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } 
        // Move front back by one
        else {
            front--;
        }
        arr[front] = x;     // Insert the element
        return true;
    }

    // Insert element at the rear
    bool pushRear(int x) {
        // Check for deque overflow
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return false;
        } 
        // If deque is empty
        else if (front == -1) {
            front = rear = 0;
        } 
        // Wrap around if rear is at the last position
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        } 
        // Move rear forward by one
        else {
            rear++;
        }
        arr[rear] = x;      // Insert the element
        return true;
    }

    // Delete element from the front
    int popfront() {
        if (front == -1) {  // Check for underflow
            return -1;
        }
        int ans = arr[front];   // Store the element to return
        arr[front] = -1;        // Optional: Clear the element

        // If deque has only one element
        if (front == rear) {
            front = rear = -1;
        } 
        // Wrap around if front is at the end
        else if (front == size - 1) {
            front = 0;
        } 
        // Move front forward by one
        else {
            front++;
        }
        return ans;          // Return the removed element
    }

    // Delete element from the rear
    int poprear() {
        if (front == -1) {   // Check for underflow
            return -1;
        }
        int ans = arr[rear];    // Store the element to return
        arr[rear] = -1;         // Optional: Clear the element

        // If deque has only one element
        if (front == rear) {
            front = rear = -1;
        } 
        // Wrap around if rear is at the beginning
        else if (rear == 0) {
            rear = size - 1;
        } 
        // Move rear back by one
        else {
            rear--;
        }
        return ans;            // Return the removed element
    }

    // Get front element
    int getfront() {
        if (isEmpty()) {      // Check if deque is empty
            return -1;
        }
        return arr[front];    // Return front element
    }

    // Get rear element
    int getrear() {
        if (isEmpty()) {      // Check if deque is empty
            return -1;
        }
        return arr[rear];     // Return rear element
    }

    // Check if deque is empty
    bool isEmpty() {
        if (front == -1) {
            return true;
        } else {
            return false;
        }
    }

    // Check if deque is full
    bool isFull() {
        // Condition for deque overflow (circular wrap-around)
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return true;
        } else {
            return false;
        }
    }
};

// Main function to test the deque operations
int main() {
    MyDeque dq(5);  // Create a deque of size 5

    dq.pushRear(10);     // Insert 10 at rear
    dq.pushRear(20);     // Insert 20 at rear
    dq.pushfront(5);     // Insert 5 at front
    dq.pushfront(1);     // Insert 1 at front

    cout << "Front: " << dq.getfront() << endl;   // Output current front
    cout << "Rear: " << dq.getrear() << endl;     // Output current rear

    cout << "Pop front: " << dq.popfront() << endl;   // Remove from front
    cout << "Pop rear: " << dq.poprear() << endl;     // Remove from rear

    cout << "Front: " << dq.getfront() << endl;   // Output front after pops
    cout << "Rear: " << dq.getrear() << endl;     // Output rear after pops

    return 0;
}
