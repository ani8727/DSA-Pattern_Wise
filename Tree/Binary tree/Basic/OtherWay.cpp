#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

Node* buildTree(vector<int> nums){
    int n=nums.size();
    if(!n || nums[0]==-1) return nullptr;

    queue<Node*> q;
    Node* root=new  Node(nums[0]);
    q.push(root);

    int i=1;
    while(!q.empty() && i<n){
        Node* curr=q.front();
        q.pop();
        if(i<n && nums[i]!=-1){
            curr->left=new Node(nums[i]);
            q.push(curr->left);
        }
        i++;
        if(i<n && nums[i]!=-1){
            curr->right=new Node(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// level wise traverse
void levelT(Node* root){
    if(!root){
        cout<<"NULL"<<endl;
        return;
    }
    queue<Node*> q;
    Node* curr=root;
    q.push(curr);
    while(!q.empty()){
        int level=q.size();
        for(int i=0;i<level;i++){
            curr=q.front();
            q.pop();
            cout<<curr->val<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<<endl;
    }
    cout<<endl;
}
//  left view of level OR right view
void lView(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level=q.size();

        for(int i=0;i<level;i++){
            Node* curr=q.front();
            q.pop();

            // left view
            if(i==0) cout<<curr->val<<" ";
            // right view
            if(i==level-1) cout<<curr->val<<" ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

// vertical view - root-> hd=0
void vView(Node* root){
    if(!root) return;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;

    Node* curr=root;
    int hd=0;
    q.push({curr, hd});

    while(!q.empty()){
        Node* curr = q.front().first;
        int hd = q.front().second;

        q.pop();

        mp[hd].push_back(curr->val);

        if(curr->left) q.push({curr->left, hd-1});
        if(curr->right) q.push({curr->right, hd+1});
    }

    for(auto &x: mp){
        for(int val: x.second)
            cout<<val<<" ";
        cout<<endl;
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

    cout<<"Level Wise Traverse"<<endl;
    levelT(root);

    cout<<"Left and Right View"<<endl;
    lView(root);

    cout<<"Vertical View "<<endl;
    vView(root);

    return 0;
}