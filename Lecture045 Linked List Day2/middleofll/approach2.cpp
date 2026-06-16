#include<iostream>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to find the middle node using slow and fast pointers
Node* getMiddle(Node* head) {
    // Base cases: if list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // If only two nodes, return the second as middle (per your logic)
    if (head->next->next == nullptr) {
        return head->next;
    }

    Node* slow = head;         // Slow pointer moves one step at a time
    Node* fast = head->next;   // Fast pointer moves two steps at a time

    // Traverse the list
    while (fast != nullptr) {
        fast = fast->next;     // Move fast one step
        if (fast != nullptr) {
            fast = fast->next; // Move fast another step if possible
        }
        slow = slow->next;     // Move slow one step
    }

    return slow; // When fast reaches end, slow is at the middle
}

// Wrapper function
Node* findMiddle(Node* head) {
    return getMiddle(head);
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test
int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << "Original List: ";
    printList(head);

    Node* middle = findMiddle(head);

    if (middle != nullptr)
        cout << "Middle Node: " << middle->data << endl;
    else
        cout << "List is empty!" << endl;

    return 0;
}
