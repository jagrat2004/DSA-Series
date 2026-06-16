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

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (head == nullptr) {
        return true; // Empty list is considered circular
    }

    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
  if(temp == head){
    return true;
  }
  return false;
}

int main() {
    // Create nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = nullptr; // This makes the list circular

    // Check if list is circular
    if (isCircular(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    return 0;
}
