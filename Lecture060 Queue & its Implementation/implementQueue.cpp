#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int size;
    int rear;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;  // Optional: not needed unless for debug
            qfront++;
            // Reset indices when queue becomes empty
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (isEmpty()) {
            return -1;
        } else {
            return arr[qfront];
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl; // 10

    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front: " << q.front() << endl;     // 20

    cout << "Dequeue: " << q.dequeue() << endl; // 20
    cout << "Dequeue: " << q.dequeue() << endl; // 30
    cout << "Dequeue: " << q.dequeue() << endl; // -1

    cout << "Is Empty: " << q.isEmpty() << endl; // 1 (true)

    return 0;
}
