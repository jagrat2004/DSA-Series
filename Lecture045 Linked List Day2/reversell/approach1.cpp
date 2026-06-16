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


// Function to reverse a singly linked list
Node* reverseLinkedList(Node* head) {
    // Base case: if list is empty or has only one node, return head as it is already reversed
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* prev = nullptr;      // Pointer to keep track of the previous node (initially null)
    Node* curr = head;         // Pointer to the current node being processed (starts from head)
    Node* forward = nullptr;   // Pointer to temporarily store the next node

    // Traverse through the list
    while (curr != nullptr) {
        forward = curr->next;     // Store the next node before breaking the link
        curr->next = prev;        // Reverse the link: current node now points to the previous node
        prev = curr;              // Move prev to current node (one step forward)
        curr = forward;           // Move curr to the next node (original next)
    }

    return prev;  // prev becomes the new head of the reversed list
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
    // Create linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
