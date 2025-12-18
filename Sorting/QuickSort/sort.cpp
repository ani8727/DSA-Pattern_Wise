#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int left, int right){
    int pivot=nums[right];

    int i=left-1;
    for(int j=left;j<right;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[i], nums[j]);
        }   
    }
    swap(nums[i+1], nums[right]);
    return i+1;
}

void quickSort(vector<int>& nums, int left, int right){
    if(left<right){
        int pi=partition(nums,left,right);
        
        quickSort(nums,left, pi-1);
        quickSort(nums, pi+1, right);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    quickSort(nums, 0, n-1);

    for(int i: nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}