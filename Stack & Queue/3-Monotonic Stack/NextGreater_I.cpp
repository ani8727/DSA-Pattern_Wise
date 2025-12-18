// 496. Next Greater Element I

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

void nextGreater(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;
    stack<int> st;
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(!st.empty()){
            mp[nums2[i]]=st.top();
        }else{
            mp[nums2[i]]=-1;
        }
        st.push(nums2[i]);
    }

    for(int i=0;i<nums1.size();i++){
        nums1[i]=mp[nums1[i]];
    }
}

int main(){
    int n;
    int m;
    cin>>n>>m;

    vector<int>nums1(n), nums2(m);

    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }

    nextGreater(nums1,nums2);

    for(int i: nums1){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}