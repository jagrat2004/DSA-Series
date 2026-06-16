#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
   //constructor
   Node(int d){
    this -> data = d;
    this -> prev = nullptr;
    this-> next = nullptr;
   }
};
//traversal
void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != nullptr){
        len++;
        temp = temp -> next;
    }
    return len;
}

void InsertAtHead(Node* &tail, Node* &head, int d){
    if(head == nullptr){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
    
}

void InsertAtTail(Node* &head, Node* &tail, int d){
    if(head == nullptr){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
    Node* temp = new Node(d);
    tail->next = temp;
    temp -> prev = tail;
    tail = temp;
}
}
void InsertAtPosition(Node* &tail , Node* &head, int position, int d){
    if(position == 1){
        InsertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == nullptr){
        InsertAtTail(head, tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp->next;
    temp->next->prev =nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtHead(tail, head, 23);
    print(head);
    InsertAtHead(tail, head, 13);
    print(head);
    InsertAtHead(tail, head, 46);
    print(head);
    InsertAtHead(tail, head, 92);
    print(head);
    InsertAtHead(tail, head, 7);
    print(head);
    InsertAtPosition(tail, head, 3 ,11);
    print(head);
    InsertAtPosition(tail, head, 5 ,42);
    print(head);
}