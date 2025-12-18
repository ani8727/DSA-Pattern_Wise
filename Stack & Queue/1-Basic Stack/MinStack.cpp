// create a minStack prfoem all opeartion also perform a MinElement

#include<iostream>
#include<stack>
using namespace std;

class Stack{
    private:
        stack<int> st;
        stack<int> minSt;
    public:
        void push(int val){
            st.push(val);
            if(minSt.empty() || minSt.top()>val){
                minSt.push(val);
            }
        }
        void pop(){
            if(st.empty()) return;
            if(st.top()==minSt.top())
                minSt.pop();
            st.pop();
        }
        int top(){
            if(st.empty()) return -1;
            return st.top();
        }
        int getMin(){
            if(minSt.empty()) return -1;
            return minSt.top();
        }
};

int main(){
    Stack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;



    return 0;


}