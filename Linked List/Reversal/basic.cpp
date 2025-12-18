#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

Node* makeList(vector<int>& nums){
    if(nums.empty()) return NULL;

    Node* head=new Node(nums[0]);
    Node* temp=head;

    for(int i=1;i<nums.size();i++){
        temp->next=new Node(nums[i]);
        temp=temp->next;
    }
    return head;
}

void traverse(Node* head){
    if(head){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }else{
        cout<<"NULL"<<endl;
    }
}

Node* reverse(Node* head){
    if(!head || !head->next) return head;

    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Node* head=makeList(nums);

    traverse(head);

    Node* newHead=reverse(head);

    traverse(newHead);

    return 0;


}