#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }


//The destructor you've written is designed to automatically free memory used by the linked list nodes when a Node object is deleted. 
//In C++, the this pointer refers to the current object instance, and it's used here to explicitly access the node’s data and next pointer. The line int value = this->data; 
//retrieves the value stored in the current node, which is later used in a message to confirm the node's deletion. The condition if (this->next != nullptr) checks whether the current node points to another node. If it does, the line delete next; is executed, 
//which triggers the destructor on the next node. This process continues recursively, ensuring that when you delete the head of the list, all connected nodes are also deleted one by one. After deleting the next node, this->next = nullptr; ensures the pointer is cleared to prevent dangling references.
// Finally, a message is printed using cout, indicating that memory has been freed for the node with a specific data value. This destructor helps in managing memory safely by cleaning up the entire list starting from any node, particularly useful when you delete the head node. However, since it uses recursion, 
//it's best suited for smaller lists, as very long lists may cause stack overflow due to deep recursive

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != nullptr){
            delete next;
            this -> next = nullptr;
        }
        cout << "memory is free for the node without data" << value << endl;
    }
};
void InsertAtHead(Node* &head , int d){
   Node* temp = new Node(d);
   temp -> next = head;
   head = temp;
}

void InsertAtTail(Node* &tail , int d){
   Node* temp = new Node(d);
   tail -> next = temp;
   tail = tail -> next;
}

void InsertAtPosition(Node* &tail , Node* &head, int Position, int d ){
    if( Position == 1){
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < Position - 1){
        temp = temp -> next;
        cnt++;
    }
    if(temp->next == nullptr){
        InsertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int Position, Node* &head){
    // If the node to be deleted is the first node
    if(Position == 1){
        Node* temp = head;             // Store the current head node in a temporary pointer
        head = head -> next;           // Move the head pointer to the next node
        temp -> next = nullptr;        // Optional: disconnect the deleted node from the list
        delete temp;                   // Free the memory occupied by the old head
    } else {
        Node* curr = head;             // Start from the head of the list
        Node* prev = nullptr;          // Previous pointer to keep track of the node before current
        int cnt = 1;                   // Counter to track current position

        // Traverse the list to reach the desired position
        while(cnt < Position){
            prev = curr;              // Move prev to current node
            curr = curr -> next;      // Move curr to next node
            cnt++;                    // Increment position counter
        }

        prev -> next = curr -> next;  // Bypass the node to be deleted
        curr -> next = nullptr;       // Optional: disconnect the node from the list
        delete curr;                  // Free the memory of the node to be deleted
    }
}


//traverse a linked list
void print(Node* head){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    
}
int main(){
Node* first = new Node(10);
Node* head = first;
Node* tail = first;
InsertAtTail(tail, 12);
print(head);
InsertAtTail(tail, 13);
print(head);
InsertAtTail(tail, 14);
print(head);
InsertAtTail(tail, 15);
print(head);

InsertAtPosition(tail, head, 4, 22);
print(head);

deleteNode(3, head);
print(head);

return 0;

}
