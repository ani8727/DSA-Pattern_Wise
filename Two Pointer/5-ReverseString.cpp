// 344. Reverse String 
// You must do this by modifying the input array in-place with O(1) extra memory.

#include<iostream>
using namespace std;

// two pointer approach - opposite direction
void reverse(string& s){
    int n=s.length();

    int left=0, right=n-1;
    while(left<right){
        swap(s[left++], s[right--]);
    }
}

int main(){
    string s;
    cin>>s;

    cout<<s<<endl;
    reverse(s);

    cout<<s<<endl;

    return 0;

}