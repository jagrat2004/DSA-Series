#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
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

void countLeaves(node* root, int &count) {
    if(root == nullptr) {         // base case: empty node
        return;
    }
    countLeaves(root->left, count);                          // go left
    if(root->left == nullptr && root->right == nullptr) {    // leaf condition
        count++;                                             // increment count
    }
    countLeaves(root->right, count);                         // go right
}


int NoofLeafNodes(node* root) {
    int count = 0;
    countLeaves(root, count);    
    return count;                
}

int main() {
    node* root = nullptr;              // Fix 7: initialize root to nullptr first
    root = buildTree(root);            // Fix 8: store return value separately
    
    cout << "Number of Leaf Nodes: " << NoofLeafNodes(root) << endl;
    return 0;
}