#include<bits/stdc++.h>
using namespace std;

int subArray(vector<int> nums, int target){
    int n=nums.size();

    int count=0;
    int prod=1;
    int left=0;
    int right=0;

    while(right<n){
        prod*=nums[right];
        if(prod>=target){
            prod/=nums[left];
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}

int main(){
    string s;
    getline(cin, s);
    int target;
    cin>>target;

    stringstream ss(s);

    vector<int> nums;
    string temp;
    while(getline(ss, temp, ',')){
        nums.push_back(stoi(temp));
    }

    int ans=subArray(nums,target);

    cout<<ans<<endl;

    return 0;
}