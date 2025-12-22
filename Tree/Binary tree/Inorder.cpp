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

Node* buildTree(vector<int>& nums,int &i){
    if(i>=nums.size() || nums[i]==-1) {
        i++;
        return NULL;
    }
        
    Node* root=new Node(nums[i++]);
    
    root->left=buildTree(nums,i);
    root->right=buildTree(nums,i);

    return root;
}

// using vector
void inorderTraverse(Node* root){
    if(!root){
        return;
    }

    inorderTraverse(root->left);
    cout<<root->val<<" ";
    inorderTraverse(root->right);
}

// using stack
void inTraversal(Node *root){
    stack<Node*> st;
    Node* curr=root;

    while(curr!=NULL || !st.empty()){
        // reach to left most leaf
        while(curr != NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->val<<" ";

        // visit uske right ko
        curr=curr->right;
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

    cout<<"Inorder Traversal"<<endl;
    inorderTraverse(root);
    cout<<endl;

    cout<<"Traversal using Stack: "<<endl;
    inTraversal(root);
    cout<<endl;

    return 0;
}