//  Pattern DFS - height tree
// all problem related to this pattern

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int data){
        val=data;
        left=right=nullptr;
    }
};

Node* buildTree(vector<int>& nums){
    int n=nums.size();
    if(n==0 || nums[0]==-1){
        return nullptr;
    }
    Node* root=new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<n){
        Node* node=q.front();
        q.pop();

        if(i<n && nums[i]!=-1){
            node->left=new Node(nums[i]);
            q.push(node->left);
        }
        i++;
        if(i<n && nums[i]!=-1){
            node->right=new Node(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// Height of node
int height(Node* root){
    if(root==nullptr)
        return 0;
    
    return 1+max(height(root->left),height(root->right));
}

// height of edge
int heightEdge(Node* root){
    if(!root)
        return -1;

    return 1+max(heightEdge(root->left),heightEdge(root->right));
}

// Size
int size(Node* root){

    if(root==nullptr)
        return 0;
    
    return 1+size(root->left)+size(root->right);
}

// Sum
int sum(Node* root){

    if(!root)
        return 0;
    
    return root->val+sum(root->left)+sum(root->right);
}

// max value Node
int maxNode(Node* root){

    if(!root)
        return 0;  // as requuirement

    int rootVal=root->val;
    int childValue=max(maxNode(root->left),maxNode(root->right));

    return max(rootVal,childValue);
}


int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=buildTree(nums);

    cout<<endl;
    cout<<"Height of root: "<<height(root)<<endl;
    cout<<"Height edges of root: "<<heightEdge(root)<<endl;
    cout<<"Size of Tree: "<<size(root)<<endl;
    cout<<"Sum: of tree: "<<sum(root)<<endl;
    cout<<"Maximum Node Value: "<<maxNode(root)<<endl;

    return 0;
}