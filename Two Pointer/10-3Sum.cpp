// 15. 3Sum  - not contains dublicate in solution

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    int n=nums.size();
    if(n<3) return {};

    sort(nums.begin(),nums.end());
    
    // set<vector<int>> s;
    vector<vector<int>> ans;
    
    for(int i=0;i<n;i++){
        if(nums[i] > 0) break;
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left=i+1,  right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right]+nums[i];
            if(sum==0){
                // s.insert({nums[i],nums[left],nums[right]});
                ans.push_back({nums[i],nums[left],nums[right]});
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;

                left++; right--;
            }
            else if(sum>0)  right--;
            else left++;
        }
    }
    // for(auto &v: s){
    //     ans.push_back(v);
    // }

    return ans;
}

int main(){
    string s;
    getline(cin, s);

    stringstream ss(s);

    vector<int> nums;
    string temp;

    while(getline(ss, temp, ',')){
        nums.push_back(stoi(temp));
    }

    vector<vector<int>> ans=threeSum(nums);

    for(vector<int> num: ans){
        for(int i: num){
            cout<<i<<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}