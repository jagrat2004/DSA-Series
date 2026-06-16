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

Node* uniqueSortedList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a sorted list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(head);

    head = uniqueSortedList(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
