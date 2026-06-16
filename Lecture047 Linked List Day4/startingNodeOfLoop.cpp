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

// Modified Floyd's function to return the intersection node
Node* detectCycle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Intersection point
        }
    }
    return nullptr; // No cycle
}

// Get starting node of the cycle
Node* getStartingNode(Node* head) {
    if(head == nullptr){
        return nullptr;
    }
    Node* intersection = detectCycle(head);
    if (intersection == nullptr) {
        return nullptr; // No cycle
    }

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow; // Starting node of the cycle
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

    // Detect and report loop
    Node* start = getStartingNode(head);
    if (start != nullptr) {
        cout << "Loop detected. Starting node of loop is: " << start->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}
