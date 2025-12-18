#include<iostream>
#include<vector>
using namespace std;


//  Bubble sort -> 1. outer loop = 0 to n-1
//                 2. inner loop= 0 to n-1-i
//                 3. adde swapped - if not true in inner loop means already sorted break;

void sort(vector<int>& nums){
    int n=nums.size();

    for(int i=0;i<n-1;i++){  // not need to last check - at that point all will be sorted

        for(int j=0;j<n-1-i;j++) // last index not check and also ith numof last index also sorted so not need to check
        {
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

void sort2(vector<int>& nums){
    int n=nums.size();

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
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

    for(int i:nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}