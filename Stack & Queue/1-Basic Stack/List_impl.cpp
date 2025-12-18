// Stack Implementation using LinkedList

#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            val=data;
            next=NULL;
        }
};

class Stack{
    Node* head=NULL;
    public:
        void push(int x){
            Node* newNode=new Node(x);
            newNode->next=head;
            head=newNode;
        }
        void pop(){
            if(head==NULL){
                throw runtime_error ("Empty Stack");
            }
            Node* temp=head;
            head=head->next;
        }
        int top(){
            if(head==NULL){
                cout<<("Empty Stack")<<endl;
                return -1;
            }
            return head->val;
        }
        bool empty(){
            return head==NULL;
        }
        int size(){
            if(head==NULL)
                return 0;
            Node* temp=head;
            int count=0;
            while(temp){
                count++;
                temp=temp->next;
            }
            return count;
        }
};

int main(){
    
    Stack st;

    st.push(5);
    st.push(100);
    st.push(15);

    cout<<st.size()<<endl;

    st.pop();
    st.pop();

    cout<<st.top()<<endl;

    cout<<st.empty()<<endl;

    st.pop();

    cout<<st.empty()<<endl;

    return 0;

}