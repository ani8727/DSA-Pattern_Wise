// 112. Path Sum

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

bool inorder(Node* root, int sum, int targetSum){
    if(!root)
        return false;
        
    sum+=root->val;

    // if we rached leaf node
    if(!root->left && !root->right){
        if(sum==targetSum)
            return true;
        return false;
    }

    return (inorder(root->left, sum, targetSum) || inorder(root->right, sum, targetSum));
}

bool hasPathSum(Node* root, int targetSum) {
    int sum=0;

    return inorder(root, sum, targetSum);
}