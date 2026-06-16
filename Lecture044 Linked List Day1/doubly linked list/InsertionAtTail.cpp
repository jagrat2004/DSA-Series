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
        this -> next = nullptr;
    }
};
void print(Node* head){
   Node* temp = head;
   while(temp != nullptr){
    cout<< temp->data << " ";
    temp = temp-> next;
   }
   cout << endl;
}
void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp -> prev = tail;
    tail = temp;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtTail(tail, 23);
    print(head);
    InsertAtTail(tail, 13);
    print(head);
    InsertAtTail(tail, 46);
    print(head);
    InsertAtTail(tail, 92);
    print(head);
    InsertAtTail(tail, 7);
    print(head);
}