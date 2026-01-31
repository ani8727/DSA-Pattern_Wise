// 1162. As Far from Land as Possible
// Mutli Source BFS- for all land then explore

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int farLand(vector<vector<int>>& grid, int n){

    // store all nad pair - for traverse multi source
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
                q.push({i,j});
        }
    }

    // now check if all land or all water - then not possible
    if(q.empty() || q.size()==n*n)
        return -1;
    
    // direction
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    int dist=-1;
    while(!q.empty()){
        int level=q.size();
        dist++;

        while(level--){
            auto p=q.front();
            q.pop();

            int x=p.first;
            int y=p.second;

            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];

                if((nx>=0 && ny>=0 && nx<n && ny <n) && (grid[nx][ny]==0)){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
    }
    return dist;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout<<"enter 0 and 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    cout<<"As far land Possible -> distance: "<<farLand(grid,n)<<endl;

    return 0;
}