#include<iostream>
using namespace std;

// Template Node class
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to merge two sorted linked lists in-place
Node<int>* solve(Node<int>* first, Node<int>* second) {
    if (first->next == nullptr) {
        first->next = second;
        return first;
    }

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = nullptr;

    while (next1 != nullptr && curr2 != nullptr) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == nullptr) {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

// Determines which list to start from (the one with smaller head)
Node<int>* sortTwoList(Node<int>* first, Node<int>* second) {
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

// Helper function to insert a node at the end
void insertAtTail(Node<int>* &head, int data) {
    Node<int>* newNode = new Node<int>(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node<int>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print the linked list
void printList(Node<int>* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node<int>* first = nullptr;
    Node<int>* second = nullptr;

    // First sorted list: 1 -> 3 -> 5 -> 7
    insertAtTail(first, 1);
    insertAtTail(first, 3);
    insertAtTail(first, 5);
    insertAtTail(first, 7);

    // Second sorted list: 2 -> 4 -> 6 -> 8
    insertAtTail(second, 2);
    insertAtTail(second, 4);
    insertAtTail(second, 6);
    insertAtTail(second, 8);

    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    Node<int>* merged = sortTwoList(first, second);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
