// 658. Find K Closest Elements

#include<bits/stdc++.h>
using namespace std;

vector<int> kClosest(vector<int>& nums, int k, int x){
    int n=nums.size();

    int left=0;
    int right=n-1;

    while(right-left+1>k){
        if(abs(nums[left]-x)>abs(nums[right]-x))
            left++;
        else
            right--;
    }

    // vector<int> ans;
    // ans.insert(ans.end(),nums.begin()+left, nums.begin()+right+1);
    return vector<int>(nums.begin()+left,nums.begin()+right+1);
    // return ans;
}

int main(){
    int k, x;
    cout<<" k and x: ";
    cin>>k>>x;
    int n;
    cout<<" size and element :";
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=kClosest(nums,k,x);

    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}