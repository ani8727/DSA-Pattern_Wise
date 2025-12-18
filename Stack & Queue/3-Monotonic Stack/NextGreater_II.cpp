// 503. Next Greater Element II

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreater(vector<int>& nums){
    int n=nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i%n]){
            st.pop();
        }
        if(!st.empty()) ans[i%n]=nums[st.top()];
        st.push(i%n);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> ans=nextGreater(nums);

    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}