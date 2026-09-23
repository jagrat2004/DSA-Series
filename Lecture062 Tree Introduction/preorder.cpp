#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

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
    cout<<"enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right"<<endl;
    root->right = buildTree(root->right);
    return root;

}
void preorder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}
int main() {
    node* root = nullptr;
    root = buildTree(root);

    cout << "\npreorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}