#include<iostream>
#include<vector>
using namespace std;

// Note - 1. outer running n-1 and inner running at last
//         2. not any optimize way to break like bubble but i==min_id same not swap

void sort(vector<int>& nums){
    int n=nums.size();

    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[min_idx]){
                min_idx=j;
            }
        }
        // swap(nums[i],nums[min_idx]);
        if(i!=min_idx) swap(nums[i],nums[min_idx]);  // only way to apply some optimize
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums);

    for(int i: nums){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}