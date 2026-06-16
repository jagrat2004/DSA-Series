#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int val){
        data = val;
        next = nullptr;
    }
};
// Recursive helper function to reverse the linked list
void reverse(Node* &head, Node* &curr, Node* prev) {
    // Base case: if current node is null, we've reached the end of the list
    if (curr == nullptr) {
        head = prev;  // Set the head to the last non-null node (which is the new head)
        return;       // Terminate recursion
    }

    Node* forward = curr->next;   // Store the next node before breaking the link
    reverse(head, forward, curr); // Recursive call with next node as current and current as previous
    curr->next = prev;            // Reverse the current node's link after recursion unwinds
}

// Wrapper function to initiate the recursive reversal
Node* reverseLinkedList(Node* head) {
    Node* curr = head;         // Initialize current pointer to head
    Node* prev = nullptr;      // Initialize previous pointer to nullptr (as new tail will point to nullptr)
    reverse(head, curr, prev); // Call the recursive function
    return head;               // Return the new head of the reversed list
}

void print(Node* head){
    while(head != nullptr){
        cout<< head->data<<" ";
        head = head->next;
    }
    cout<< endl;
}
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    print(head);

    head = reverseLinkedList(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}
