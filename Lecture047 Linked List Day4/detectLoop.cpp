#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool floydDetectLoop(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false; // No loop
}



int main() {
    // Creating nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creating a loop (back to second)

    // Checking for loop
    if (floydDetectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}
