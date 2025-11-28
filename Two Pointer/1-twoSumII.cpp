// L-167 -> Two Sum II - array input should be sorted

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> twoSum(vector<int>& nums, int target){
    int n=nums.size();

    int left=0, right=n-1;

    while(left<right){
        if(nums[left]+nums[right]==target){
            return {left+1, right+1};
        }else if(nums[left]+nums[right]<target){
            left++;
        }else{
            right--;
        }
    }
    return {-1,-1};
}

int main(){
    vector<int> nums={2,3,5,8,9,10};
    int target=17;
    
    pair<int, int> ans=twoSum(nums, target);

    cout<<ans.first<<" "<<ans.second;

    return 0;
}