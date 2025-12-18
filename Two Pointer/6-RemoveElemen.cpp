// 27. Remove Element
// delete all occrence of given elemt at in-place 

#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int n=nums.size();

    int read=0;
    int write=0;
    while(read<n){
        if(nums[read]!=val){
            swap(nums[read],nums[write++]);
        }
        read++;
    }
    return write;
}

int main(){
    vector<int>nums={0,1,2,2,3,0,4,2};
    int val=2;

    int n=removeElement(nums, val);

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;

    return 0;
}