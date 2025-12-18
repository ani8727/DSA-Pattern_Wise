//  763. Partition Labels

#include<iostream>
#include<vector>

using namespace std;

vector<int> maxPartition(string s){
    int n=s.length();

    vector<int> lastOccrence(16,0);

    for(int i=0;i<n;i++){
        lastOccrence[s[i]-'a']=i;
    }

    int endParttion=0, startPartition=0;
    vector<int> partitionSize;

    for(int i=0;i<n;i++){
        endParttion=max(endParttion, lastOccrence[s[i]-'a']);

        if(i==endParttion){
            partitionSize.push_back(i-startPartition+1);
            startPartition=i+1;
        }
    }
    return partitionSize;
}
int main(){
    string s;
    cin>>s;

    vector<int> ans= maxPartition(s);

    for(int i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}