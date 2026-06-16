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
void InsertAtTail(Node* &tail, int d){
   Node* temp = new Node(d);
   tail -> next = temp;
   tail = tail -> next;
}
void print(Node* head){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    } 
    cout<< endl;
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
return 0;

}