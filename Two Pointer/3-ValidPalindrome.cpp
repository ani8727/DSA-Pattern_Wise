#include<iostream>
using namespace std;

bool isvalid(string s){
    int left=0, right =s.length()-1;

    while(left<right){
        if(!isalnum(s[left])){
            left++; continue;
        }
        if(!isalnum(s[right])){
            right--; continue;
        }
        if(tolower(s[left]!=tolower(s[right]))){
            return false;
        }
        left++; right--;
    }
    return true;
}   

int main(){
    // string s="a man, a plan, a canal : panama";
    string s="abasb";

    if(isvalid(s)){
        cout<<"Valid Paindrom"<<endl;
    }else{
        cout<<"Not Valid"<<endl;
    }
    return  0;
}