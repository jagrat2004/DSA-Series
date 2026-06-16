#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Class definition for a circular queue
class circularQueue{
    int *arr;      // Pointer to array used to implement the queue
    int front;     // Index of front element
    int rear;      // Index of rear element
    int size;      // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    circularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1; // Queue is initially empty
    }

    // Function to insert an element into the circular queue
    bool enqueue(int value){
        // Check if the queue is full
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            cout<<"queue is full"<<endl;
            return false;
        }
        // If the queue is empty
        else if(front == -1){
            front = rear = 0;
        }
        // If rear is at the end and front is not at 0, wrap around
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        // Normal case, move rear forward
        else{
            rear++;
        }

        // Insert the value
        arr[rear] = value;
        return true;
    }

    // Function to delete an element from the circular queue
    int dequeue(){
        // If queue is empty
        if(front == -1){
          cout<<"queue is empty"<<endl;
          return -1;
        }

        int ans = arr[front]; // Store the value to return
        arr[front] = -1;      // Optional: mark as removed

        // If this was the last element
        if(front == rear){
            front = rear = -1;
        }
        // If front is at the end, wrap around
        else if(front == size-1){
            front = 0;
        }
        // Move front forward
        else{
            front++;
        }

        return ans; // Return dequeued value
    }

    // Function to display all elements of the queue
    void display() {
        // If queue is empty
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " "; // Print current element
            if (i == rear) break;  // Stop if we reached rear
            i = (i + 1) % size;    // Move in circular fashion
        }
        cout << endl;
    }
};

// Main function to test the circular queue
int main() {
    circularQueue q(5);  // Create a queue of size 5

    q.enqueue(10);       // Insert 10
    q.enqueue(20);       // Insert 20
    q.enqueue(30);       // Insert 30
    q.enqueue(40);       // Insert 40
    q.display();         // Display queue elements

    cout << "Dequeued: " << q.dequeue() << endl; // Remove front element
    q.display();         // Display queue after dequeue

    q.enqueue(50);       // Insert 50
    q.enqueue(60);       // This fills the queue
    q.display();         // Display full queue

    q.enqueue(70);       // Should print "queue is full"

    return 0;
}
