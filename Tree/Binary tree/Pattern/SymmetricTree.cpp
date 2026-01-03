//  check given tree is symeetric

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
    while(!q.empty() && i<n){
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

bool check(Node* l, Node* r) {
    // both null → symmetric
    if (!l && !r)
        return true;

    // one null → not symmetric
    if (!l || !r)
        return false;

    // values must match
    if (l->val != r->val)
        return false;

    // mirror comparison
    return check(l->left, r->right) && check(l->right, r->left);
}

bool isSymmetric(Node* root) {
    if (!root)
        return true;

    return check(root->left, root->right);
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=buildTree(nums);

    cout<<"Symmetric Binary tree: "<<isSymmetric(root)<<endl;

    return 0;
}