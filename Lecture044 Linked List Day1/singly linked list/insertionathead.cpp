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

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

//Traverse the linked list
void print(Node* head){
    Node* temp = head;
    while( temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    } 
    cout << endl;
}


int main(){
Node* first = new Node(10);
Node* head = first;
InsertAtHead(head, 12);
print(head);
InsertAtHead(head, 13);
print(head);
InsertAtHead(head, 14);
print(head);
InsertAtHead(head, 15);
print(head);
return 0;

}