#include<iostream>
using namespace std;

void insertAtTail(Node* &tail, Node* curr){
    tail ->next = curr;
    tail = curr;
}


int main(){

}