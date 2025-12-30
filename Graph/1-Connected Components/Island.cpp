// 2. Number of Island-200
#include<iostream>
#include<vector>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){

    grid[i][j]='2';

    for(int d=0;d<4;d++){
        int x=i+dx[d];
        int y=j+dy[d];

        if(x>=0 && y>=0 && x<m && y<n && grid[x][y]=='1'){
            dfs(grid,x,y,m,n);
        }
    }
}
int numIsland(vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();

    int count=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j,m,n);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>grid[i][j];
        }
    }

    cout<<"Islands: "<<numIsland(grid)<<endl;

    return 0;
}