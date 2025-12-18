#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

/*
bool isValid(string s){
    stack<char> st;
    unordered_map<char, char> mp={ {')','('},
                                   {'}','{'},
                                   {']','['} };
    for(char ch:s){
        if(mp.count(ch)){ // iska opening exist karta hia to ye closing hai
            if(st.empty() || st.top()!=mp[ch]) // koi bhi shi hai to ye false hoga
                return false;
            st.pop(); // koi bhi shi nhi hia to st ke toppar hi closing hai ch ka
        } else{ // agar opening exit nhi katta to ye opening hi hoga
            st.push(ch);
        }
    }
    return st.empty();

}
*/

bool isValid(string s){
    stack<char> st;

    for(char ch: s){
        if(ch=='(') st.push(')');
        else if(ch=='{') st.push('}');
        else if(ch=='[') st.push(']');
        else{
            if(st.empty() || st.top() != ch)
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;

    if(isValid(s))
        cout<<"Valid"<<endl;
    else
        cout<<"Not Valid"<<endl;

    return 0;
}
