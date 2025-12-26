// Level order WITHOUT nulls (complete tree)
// Level order WITH nulls (REALISTIC & MOST USED)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node *left, *right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

Node* buildTree(vector<int>& nums){
    if(!nums.size() || nums[0]==-1){
        return nullptr;
    }
    queue<Node*> q;
    Node* root=new Node(nums[0]);
    q.push(root);

    int i=1;
    while(!q.empty() && i<nums.size()){
        Node* curr=q.front();
        q.pop();

        //left child
        if(i<nums.size() && nums[i]!=-1){
            curr->left=new Node(nums[i]);
            q.push(curr->left);
        }
        i++;
        //right child
        if(i<nums.size() && nums[i] != -1){
            curr->right=new Node(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void traverse(Node* root){
    if(!root) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=buildTree(nums);

    traverse(root);

    return 0;

}