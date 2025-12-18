// Next Greater Element
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void nextGreater(vector<int>& nums){
    int n=nums.size();
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        int curr=nums[i];
        while(!st.empty() && st.top()<=curr){
            st.pop();
        }
        if(!st.empty()){
            nums[i]=st.top();
        }else{
            nums[i]=-1;
        }
        st.push(curr);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    nextGreater(nums);

    for(int i:nums){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}