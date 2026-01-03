#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
      Node* left;
      Node* right;
      int data;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

static int idx = -1;

// pre order building
Node* buildTree(vector<int>& preOrder){

    idx++;
    if(preOrder[idx] == -1) return NULL;

    Node* root = new Node(preOrder[idx]);  // heap allocation
    root->left = buildTree(preOrder);  // build left
    root->right = buildTree(preOrder);   // build right

    return root;
}


void preTraverse(Node* root){
    if(root == NULL){
        cout<<-1 << " ";
        return;
    }
    cout<< root->data << " ";
    preTraverse(root->left);
    preTraverse(root->right);
}

int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// count of nodes
int count(Node* root){
    if(root == NULL) return 0;
    int leftC = count(root->left);
    int rightC = count(root->right);
    return 1 + leftC + rightC;
}

int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    preTraverse(root);
    return 1;
}