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

void levelOrderTraversal(node* root) {
    queue<node*> q;          // create a queue to hold node pointers
    q.push(root);            // push root node as first element
    q.push(nullptr);         // push NULL as level separator/marker

    while(!q.empty()) {                  // keep going until queue is empty
        node* temp = q.front();          // peek at front element
        q.pop();                         // remove it from queue

        if(temp == nullptr) {            // if we hit level separator
            cout << endl;                // print newline = current level done
            if(!q.empty()) {             // if more nodes still exist
                q.push(nullptr);         // push new separator for next level
            }
        }
        else {                                  // if its a valid node
            cout << temp->data << " ";          // print node value
            if(temp->left) {                    // if left child exists
                q.push(temp->left);             // add left child to queue
            }
            if(temp->right) {                   // if right child exists
                q.push(temp->right);            // add right child to queue
            }
        }
    }
}

int main() {
    node* root = buildTree(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    return 0;
}
