// 283. Move Zeroes
//  in-place and relative order not be change

#include<bits/stdc++.h>
using namespace std;

void movesZeros(vector<int>& nums){
    int n=nums.size();

    int write=0;
    int read=0;
    while(read<n){
        if(nums[read]!=0){
            swap(nums[write++], nums[read]);
        }
        read++;
    }
}

int main(){
    string s;
    getline(cin, s);

    if(s.front()=='[' && s.back()==']'){
        s=s.substr(1,s.length()-2);
    }
  
    stringstream ss (s);
    vector<int> nums;

    string temp;
    while(getline(ss, temp, ',')){
        nums.push_back(stoi(temp));
    }

    for(int num: nums){
        cout<<num<<" ";
    }cout<<endl;

    movesZeros(nums);

    for(int num: nums){
        cout<<num<<" ";
    }cout<<endl;

    return 0;

}