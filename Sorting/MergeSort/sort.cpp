#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int> num1(n1);
    vector<int> num2(n2);

    for(int i=0;i<n1;i++){
        num1[i]=nums[left+i];
    }
    for(int i=0;i<n2;i++){
        num2[i]=nums[mid+1+i];
    }

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(num1[i]<num2[j]){
            nums[k++]=num1[i++];
        }else{
            nums[k++]=num2[j++];
        }
    }
    while(i<n1){
        nums[k++]=num1[i++];
    }
    while(j<n2){
        nums[k++]=num2[j++];
    }
}

void sort(vector<int>& nums, int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;

        sort(nums, left, mid);
        sort(nums, mid+1, right);

        merge(nums, left , mid, right);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums, 0, nums.size()-1);

    for(int i:nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;

}