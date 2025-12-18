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
    Node* head=new Node(nums[0]);

    Node* temp=head;
    for(int i=1;i<nums.size();i++){
        temp->next=new Node(nums[i]);
        temp=temp->next;
    }
    return head;
}

Node* findMid(Node* head){
    if(!head) return head; 

    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

void traverse(Node* head){
    if(!head) cout<<" NULL";
    else{
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
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

    Node* mid=findMid(head);

    cout<<mid->data<<endl;

    return 0;

}