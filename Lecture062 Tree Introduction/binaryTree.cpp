#include<iostream>
#include<queue>
using namespace std;
class node{
   public:
   int data;
   node* left;
   node* right;

   node(int d){
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
   }
};

node* buildTree(node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return nullptr;
    }
    cout<<"enter the data to insert in the left"<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data to insert in the right"<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
  queue<node*>q;
  q.push(root);
  q.push(nullptr);

  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp == nullptr){
        cout<<endl;
        if(!q.empty()){
            q.push(nullptr);
        }
    }
    else{
        cout<<temp->data<<endl;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
  }

};
int main(){
   node* root = nullptr;
   root = buildTree(root);
   levelOrderTraversal(root);
   return 0;
}