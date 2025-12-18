// 209. Minimum Size Subarray Sum

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int target;
    cin>>target;

    if(s.front()=='[' && s.back()==']'){
        s=s.substr(1,s.length()-2);
    }

    stringstream ss(s);

    vector<int> nums;
    string temp;
    while(getline(ss, temp, ',')){
        nums.push_back(stoi(temp));
    }

    int n=nums.size();
    int minLength=n;
    int minSubSum=INT_MAX;

    int left=0;
    int right=0;
    int subSum=0;
    while(right<n){
        subSum+=nums[right];
        while(subSum>=target){
            int length=right-left+1;
            minLength=min(minLength,length);
            minSubSum=min(minSubSum,subSum);
            subSum-=nums[left];
            left++;
        }
        right++;
    }
     // If no valid window found
    if(minLength == n){
       minLength=0;
       minSubSum=0;
    }
    cout<<"MinLength: "<<minLength<<" "<<minSubSum<<endl;
    return 0;
}