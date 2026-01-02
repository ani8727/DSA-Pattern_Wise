// Shortest path in Binary Matrix  - 1091
//  pattern bfs - shortest path or min step

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int shortestPath(vector<vector<int>>& grid){
    int n=grid.size();

    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    // direction;
    int dx[8]={-1,1,0,0,-1,1,-1,1};
    int dy[8]={0,0,-1,1,-1,-1,1,1};

    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0]=1;

    int step=1;
    while(!q.empty()){
       int level=q.size();

       while(level--){
        auto p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second;

        if(i==n-1 && j==n-1)
            return step;
        
        for(int d=0;d<8;d++){
            int x=i+dx[d];
            int y=j+dy[d];

            if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0){
                q.push({x,y});
                grid[x][y]=1;
            }
        }
    }
    step++;
   }
   return -1;
}


int main(){
    int n;
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            grid[i][j]=k;
        }
    }

    cout<<"Shortest Path: "<<shortestPath(grid)<<endl;

    return 0;


}