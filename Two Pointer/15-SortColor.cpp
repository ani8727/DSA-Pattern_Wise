
#include<bits/stdc++.h>
using namespace std;

// appraoch - for each time
// int sortColor(vector<int>& nums){
//     int n=nums.size();
//     int count_0=0;
//     int count_1=0;
//     int count_2=0;

//     for(int num: nums){
//         if(num==0) count_0++;
//         else if(num==1) count_1++;
//         else count_2++;
//     }
//     int i=0;
//     while(count_0--) nums[i++]=0;
//     while(count_1--) nums[i++]=1;
//     while(count_2--) nums[i++]=2;
    
// }

// three pointer - dutch national algorithm
int sortColor(vector<int>& nums){
    int n=nums.size();
   
    int st=0;
    int end=n-1;
    int mid=st;

    while(mid<=end){
        if(nums[mid]==0){
            swap(nums[st],nums[mid]);
            mid++; st++;
        }
        else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[end]);
            end--;
        }
    }
}

int main(){
    string s;
    getline(cin, s);

    stringstream ss(s);

    vector<int> nums;
    string temp;
    while(getline(ss,temp,' ')){
        nums.push_back(stoi(temp));
    }

    sortColor(nums);

    for(int i: nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}