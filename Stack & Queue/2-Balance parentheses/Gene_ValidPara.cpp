// 22. Generate Parentheses
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool valid(string s){
    stack<char> st;

    for(char ch: s){
        if(ch=='(') st.push(')');
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

void solve(string& curr, int n, vector<string>& ans){

    // all brackts push now check valid or not
    if(curr.size()==n){
        if(valid(curr)){
            ans.push_back(curr);
        }
        return;
    }

    // fist option
    curr.push_back('(');
    solve(curr,n,ans);
    curr.pop_back(); // baktracking

    // second option
    curr.push_back(')');
    solve(curr, n, ans);
    curr.pop_back(); // backtraking



}

vector<string>  generateValid(int n){
    int size=n*2;
    string curr="";
    vector<string> ans;

    solve(curr, size, ans);

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> ans=generateValid(n);

    for(string s: ans){
        cout<<s<<endl;
    }
    return 0;
}