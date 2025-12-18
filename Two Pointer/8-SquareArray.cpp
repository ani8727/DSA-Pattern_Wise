// 977. Squares of a Sorted Array

#include<bits/stdc++.h>
using namespace std;

vector<int> squareArray(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);

    int left=0, right=n-1;
    for(int i=right;i>=0;i--){
        if(abs(nums[left])>abs(nums[right])){
            ans[i]=nums[left]*nums[left];
            left++;
        }else{
            ans[i]=nums[right]*nums[right];
            right--;
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin, s);

    stringstream ss(s);

    vector<int>nums;
    string temp;

    while(getline(ss, temp, ' ')){
        nums.push_back(stoi(temp));
    }

    vector<int> ans=squareArray(nums);

    for(int i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}