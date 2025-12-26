// Implementation using Matrix grid
#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n, e;
    cin>>n>>e;

    vector<vector<int>> mat(n, vector<int>(n,0));

    for(int i=1;i<=e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        mat[u][v]=w;
    }

    cout<<"matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<i<<"->"<<j<<" : "<<mat[i][j]<<endl;
        }
    }
    cout<<endl;
    return 0;
}