#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int val;
    Node* left , *right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

Node* buildTree(vector<int>& nums, int &i){
    if(i>=nums.size() || nums[i]==-1){
        i++;
        return nullptr;
    }
    Node* root= new Node(nums[i++]);
    root->left=buildTree(nums,i);
    root->right=buildTree(nums,i);
    return root;
}

void preTraversal(Node* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    preTraversal(root->left);
    preTraversal(root->right);
}
void traversal(Node* root){
    if(!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        cout<<curr->val<<" ";
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
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

    cout<<"Recursion PreTraversal"<<endl;
    preTraversal(root);

    cout<<"Satck Using"<<endl;
    traversal(root);

    return 0;
}