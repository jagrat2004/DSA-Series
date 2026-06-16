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

// Function to calculate the length of the linked list
int getLength(Node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;            // Increment length counter
        head = head->next; // Move to the next node
    }
    return len;           // Return total length
}

// Function to find the middle node of the linked list
Node* findMiddle(Node* head) {
    int len = getLength(head);     // Get total length
    int ans = len / 2;             // Index of the middle node
    Node* temp = head;             // Temp pointer to traverse
    int cnt = 0;

    // Traverse till the middle index
    while (cnt < ans) {
        temp = temp->next;
        cnt++;
    }

    return temp; // Return the middle node
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the code
int main() {
    // Create linked list: 10 -> 20 -> 30 -> 40 -> 50
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
