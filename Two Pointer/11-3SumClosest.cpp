// 16. 3Sum Closest

#include<bits/stdc++.h>
using namespace std;

int close3Sum(vector<int> nums, int target){
    int n=nums.size();
    if(n<3) return 0;

    sort(nums.begin(),nums.end());

    int closeSum=nums[0]+nums[1]+nums[2];

    for(int i=0;i<n-2;i++){
        int left=i+1, right=n-1;
        while(left<right){
            int currSum=nums[i]+nums[left]+nums[right];

            if(abs(target-currSum)<abs(target-closeSum)) closeSum=currSum;

            if(currSum==target) return currSum;  
            else if(currSum>target)  right--;
            else left++;
        }
    }
    return closeSum;
}

int main(){
    string s;
    getline(cin, s);
    int target;
    cin>>target;

    stringstream ss(s);

    vector<int> nums;
    string temp;

    while(getline(ss, temp, ' ')){
        nums.push_back(stoi(temp));
    }

    int sum=close3Sum(nums,target);

    cout<<sum<<endl;

    return 0;

}

