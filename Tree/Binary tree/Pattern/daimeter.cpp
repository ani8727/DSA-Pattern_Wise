// pattern 1.2 DFS - Diammter

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


// Diameter of tree
int height(Node* root){
    if(!root)
        return -1;
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* root){
    
    if(!root)
        return 0;
    
    // through root
    int rootUse=height(root->left)+height(root->right)+2;

    //left side - root no include
    int leftside=diameter(root->left);

    // right side - root not include
    int rightside=diameter(root->right);

    return max(rootUse,max(leftside,rightside));
}
// Optimal approach
int ans=0;

int height2(Node* root){
    if(!root){
        return -1;
    }

    int left=height2(root->left);
    int right=height2(root->right);

    ans=max(ans,left+right+2);

    return 1+max(left,right);
}
int diameter2(Node* root){
    ans=0;
    int height=height2(root);
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* root=buildTree(nums);

    cout<<"Diameter of tree: "<<diameter(root)<<endl;

    cout<<"Diameter of tree: "<<diameter2(root)<<endl;

    return 0;
}