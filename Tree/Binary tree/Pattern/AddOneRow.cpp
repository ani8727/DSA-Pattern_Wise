// 623. Add One Row to Tree

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

 Node* add(Node* root, int val, int depth, int curr){
    if(!root){
        return NULL;
    }

    // depth ke parent node 
    if(curr==depth-1){
        Node* leftTemp= root->left;
        Node* rightTemp= root->right;

        root->left=new Node(val);
        root->right=new Node(val);

        root->left->left=leftTemp;
        root->right->right=rightTemp;

        return root;
    }
        
    root->left=add(root->left,val,depth,curr+1);
    root->right=add(root->right,val,depth,curr+1);

    return root; 
}

Node* addOneRow(Node* root, int val, int depth) {
    if(depth==1){
        Node* newRoot=new Node(val);
        newRoot->left=root;

        return newRoot;
    }

    int curr=1; // level check
    return add(root, val, depth, curr);
}