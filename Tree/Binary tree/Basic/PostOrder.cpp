#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=right=NULL;
    }
};

Node* buildTree(vector<int>& nums,  int &i){
    if(i>=nums.size() || nums[i]==-1){
        i++;
        return NULL;
    }
    Node* root=new Node(nums[i++]);
    root->left=buildTree(nums,i);
    root->right=buildTree(nums,i);

    return root;
}

void postTraversal(Node* root){
    if(!root){
        return;
    }
    postTraversal(root->left);
    postTraversal(root->right);
    cout << root->val<<" ";
}

void traversal(Node* root){
    if(!root) return;
    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        
        Node* curr=st1.top();
        st2.push(curr);
        st1.pop();
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->val<<" ";
        st2.pop();
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int idx=0;
    Node* root=buildTree(nums, idx);

    cout<<"Recursion based PostOrder Traversal"<<endl;
    postTraversal(root);

    cout<<"Stack Traversal"<<endl;
    traversal(root);

    return 0;
}