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
// Recursive function to reverse the linked list
Node* reverse1(Node* head) {
    // Base case: if list is empty or has only one node, return head (no reversal needed)
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive call to reverse the smaller (rest of the) list
    Node* chotaHead = reverse1(head->next); // 'chotaHead' will be the new head of the reversed sublist

    // Reverse the link: make the next node point back to the current node
    head->next->next = head;

    // Break the original forward link to avoid cycle
    head->next = nullptr;

    // Return the new head of the reversed list (obtained from base case)
    return chotaHead;
}

// Wrapper function that starts the recursive reversal
Node* reverseLinkedList(Node* head) {
    return reverse1(head);  // Call the recursive function
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
