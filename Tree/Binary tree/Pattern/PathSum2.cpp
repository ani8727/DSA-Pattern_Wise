// 113. Path Sum II

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

 vector<vector<int>> ans;

void inorder(Node* root, int targetSum, int sum, vector<int> &path){
    if(!root) return;

    sum+=root->val;
    path.push_back(root->val);

    inorder(root->left, targetSum, sum, path);
    inorder(root->right, targetSum, sum, path);

    if(!root->left && !root->right){
        if(sum==targetSum){
            ans.push_back(path);
        }
    }
    path.pop_back();
    sum-=root->val;

    return;
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<int> path;
    int sum=0;

    inorder(root, targetSum, sum, path);

    return ans;
}

int main(){
    // main function
}