// Two Ways to implementation

// 1- LinkedList Representation(Most Common)

// 2- Array Implementation

#include<iostream>
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

// array based

class BinaryTree{
    int cap;
    int *tree;
    int size;

    public:
        BinaryTree(int n){
            cap=n;
            tree=new int[n];
            size=0;
        }
        void insert(int val){
            if(size>=cap){
                cout<<"Tree is full"<<endl;
                return;
            }
            tree[size++]=val;
        }
};

int main(){

    Node* root=NULL;

    root=new Node(5);

    if (root != NULL) {
        cout << root->val << " " << root->left << " " << root->right << endl;
    } else {
        cout << "Root is NULL" << endl;
    }

    root->left=new Node(10);
    root->right=new Node(15);

    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;

    cout<<" Array based"<<endl;

    BinaryTree t(5);

    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);

    t.insert(6);

    
    return 0;

}