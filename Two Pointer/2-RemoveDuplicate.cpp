// 26. Remove Duplicates from Sorted Array

#include<iostream>
#include<vector>
using namespace std;


// using two pointer - same direction
int removeDup(vector<int>& nums){
    int n=nums.size();
    if(n<=1) return n; 
    int j=1; // point last index of non duplicate

    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){ // not a duplicate
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}

int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};

    int n=removeDup(nums);

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;

    return 0;
}