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
        this->right = nullptr;
        this->left = nullptr;
    }
};


node* buildFromLevelOrder(node* root) {
    queue<node*> q;

    cout << "enter data for root" << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        
        cout << "enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;   
}

// inorder to verify tree built correctly
void inorder(node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = nullptr;                  
    root = buildFromLevelOrder(root);      
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}