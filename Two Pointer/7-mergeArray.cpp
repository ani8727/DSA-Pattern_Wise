// 88. Merge Sorted Array
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include<iostream>
#include<vector>

using namespace std;

void mergeArray(vector<int>& nums1, vector<int>& nums2, int m, int n){
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j])
            nums1[k--]=nums1[i--];
        else
            nums1[k--]=nums2[j--];
    }
    while(i>=0){
        nums1[k--]=nums1[i--];
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}

int main(){
    int n, m;
    cin>>m>>n;

    vector<int> nums1(m+n,0);
    vector<int> nums2(n);

    cout<<"nums: ";
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    cout<<"nums2: ";
    for(int i=0;i<n;i++){
        cin>>nums2[i];
    }

    mergeArray(nums1,nums2,m,n);

    for(int i:nums1){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}