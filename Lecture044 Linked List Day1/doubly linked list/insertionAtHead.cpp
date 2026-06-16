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

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    InsertAtHead(head, 23);
    print(head);
    InsertAtHead(head, 13);
    print(head);
     InsertAtHead(head, 46);
    print(head);
     InsertAtHead(head, 92);
    print(head);
     InsertAtHead(head, 7);
    print(head);
}