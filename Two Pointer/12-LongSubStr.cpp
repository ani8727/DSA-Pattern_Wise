// 3. Longest Substring Without Repeating Characters

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin>>s;

    unordered_map<char,int> mp;
    int maxlength=0;

    int left=0, right=0;
    while(right<s.length()){
        if(mp.count(s[right]) && mp[s[right]]>=left){
            left=mp[s[right]]+1;
        }
        mp[s[right]]=right;
        maxlength=max(maxlength,right-left+1);
        right++;
    }
    cout<<"MaxLength: "<<maxlength<<endl;
    return 0;
}