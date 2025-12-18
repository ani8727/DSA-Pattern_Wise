// i have to built a stack fo n element using array

#include<iostream>
#include<vector>
using namespace std;

class Stack{
    int cap;
    int *arr;
    int topidx;

    public:    
    Stack(int n){  // stack creation
       cap=n;
       arr=new int[cap];
       topidx=-1;
    }
    ~Stack(){  // stack delete
        delete[] arr;
    }
    
    // now we declare stack property
    void push(int x){
        if(topidx==cap-1){
            cout<<"Overflow"<<endl;
            return;
        }
        arr[++topidx]=x;
    }
    void pop(){
        if (topidx < 0) {
            cout << "Underflow" << endl;
            return;
        }
        topidx--;
    }
    int top(){
        if(topidx < 0){
            throw runtime_error("Stack Empty");
        }
        return arr[topidx];
    }
    bool empty() const{
        return topidx<=-1;
    }
    int size() const{
        return topidx+1;
    }
    void push2(int x) {
        if (topidx == cap - 1)
            resize();
        arr[++topidx] = x;
    }

   private:
    void resize() {
        cap *= 2;
        int* temp = new int[cap];
        for (int i = 0; i <= topidx; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
    }
};


int main(){
    int n;
    cin>>n;

    Stack st(n);

    st.push(5);
    st.push(4);
    st.push(3);
    st.push2(5);

    cout<<st.empty();
    st.pop();
    st.pop();

    cout<<st.size();

    st.push(1);
    st.push(5);
    cout<<st.size();

    cout<<st.top();

    return 0;
}