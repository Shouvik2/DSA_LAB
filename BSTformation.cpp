#include <bits/stdc++.h>
using namespace std;
class Node{ // This is Tree Node
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
int maxInTree(Node* root){
    if(root==NULL) return INT_MIN;
    int lMax=maxInTree(root->left);
    int rMax=maxInTree(root->right);
    return max(root->val,max(lMax,rMax));
}
void preorder(Node* root){
    if(root==NULL) return; // base case
    cout<<root->val<<" "; // root
    preorder(root->left); // left
    preorder(root->right); // right
}
void inorder(Node* root){
    if(root==NULL) return; // base case
    inorder(root->left); // left
    cout<<root->val<<" "; // root
    inorder(root->right); // right
}
void postorder(Node* root){
    if(root==NULL) return; // base case
    postorder(root->left); // left
    postorder(root->right); // right
    cout<<root->val<<" "; // root
}
Node* insertIntoBST(Node* root, int val){
    if (root == NULL)  return new Node(val);
    if (val < root->val){
        root -> left = insertIntoBST(root->left,val);
    }
    else if (val > root->val){
        root -> right = insertIntoBST(root->right,val);
    }
    return root;
}
Node* iop(Node* root){ // INORDER PREDECESSOR
    Node* pred=root->left;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred;
}
Node* deleteNode(Node* root, int key) {
    if(root==NULL) return NULL;
    if(root->val==key){
        // case 1: No child
        if(root->left==NULL && root->right==NULL) return NULL;

        // case 2:
        if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }

        // case3: 2 child node
        if(root->left!=NULL && root->right!=NULL){
            // replace the root with its inorder pred/suc
            // after replacing delete the pred/suc
            Node* pred=iop(root);
            root->val=pred->val;
            root->left=deleteNode(root->left,pred->val);
        }
    }
    else if(root->val > key){
        root->left=deleteNode(root->left,key);
    }
    else{
        root->right=deleteNode(root->right,key);
    }
    return root;
}
Node* searchBST(Node* root, int val) {
    if(root==NULL || root->val==val) return root;
    else if(root->val>val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}
int main(){
    Node* root = NULL;
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 15);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 30);
    cout << "BST" << endl;
    inorder(root);
    cout << endl;
    // Deletion
    Node* c=deleteNode(root,10);
    inorder(root);
    // Searching
    int valueToSearch=10;
    Node* result=searchBST(root,valueToSearch);
    cout<<endl;
    // Displaying the result
    if (result != NULL) cout << "Node with value " << valueToSearch << " found in the BST." <<endl;
    else  cout << "Node with value " << valueToSearch << " not found in the BST." <<endl;
}