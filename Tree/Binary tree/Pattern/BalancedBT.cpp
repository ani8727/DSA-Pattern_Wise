// balanced binary Tree

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

Node* buildTree(vector<int>& nums){
    int n=nums.size();
    if(n==0 || nums[0]==-1)
        return nullptr;
    
    Node* root=new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;
    while(!q.empty()){
        Node* node=q.front();
        q.pop();

        //left child
        if(i<n && nums[i]!=-1){
            node->left=new Node(nums[i]);
            q.push(node->left);
        }
        i++;
        // right child
        if(i<n && nums[i]!=-1){
            node->right=new Node(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int height(Node* root){
    if(!root)
        return -1;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(Node* root){
    if(!root)
        return true;
    
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    if(abs(leftHeight-rightHeight)>1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=buildTree(nums);

    cout<<"Balanced Binary tree: "<<isBalanced(root)<<endl;

    return 0;
}