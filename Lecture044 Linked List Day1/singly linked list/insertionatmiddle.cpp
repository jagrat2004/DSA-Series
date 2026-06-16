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

return 0;

}
