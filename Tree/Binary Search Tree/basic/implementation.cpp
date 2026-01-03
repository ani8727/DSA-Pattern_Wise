//  BST implementaion  - simple unbalanced Binary Search Tree

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

// inorder - stack
Node* BST(vector<int>& nums){
    int n=nums.size();

    if(n==0 || nums[0]==-1)
        return nullptr;
    
    stack<int> st;

    while()
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=BST(nums);
}
