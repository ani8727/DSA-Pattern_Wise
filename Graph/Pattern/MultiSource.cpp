// Pattern -> 2.2 : Multi-Source BFS
// work for unweighted- directed uinirected and cycle and discoonected

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Rotten Oranges (Multi-Source BFS)
int orangeRotting(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();

    queue<pair<int,int>> q;
    int fresh=0;

    // cout fresh orange
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){  // first push alread rotten orages -> we start from here
                q.push({i,j});
            }
            else if(grid[i][j]==1){ // fresh fruit - those have to rotten
                fresh++;
            }
        }
    }
    int time=0;
    // for moving - going to  neighbor
    int dx[4]={-1,1,0,0}; // left , right , up , down
    int dy[4]={0,0,-1,1};

    // bfs
    while(!q.empty() && fresh>0){
        int step=q.size();  // on that step make all first those aleady present in q
        time++;  // step increase

        for(int i=0;i<step;i++){ // first step mai jtne the sab ko process karna
            pair<int,int> p= q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx>=0 && ny>=0 && nx<m && ny<n){// is valid index
                    if(grid[nx][ny]==1){// fresh
                        grid[nx][ny]=2;  // rotten mark
                        fresh--;
                        q.push({nx,ny});
                    }

                }
            }
        }

    }
    return (fresh==0)? time:-1;
}

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           int val;
           cin>>val;
           grid[i][j]=val;
        }
    }

    cout<<"Maximum time: "<<orangeRotting(grid)<<endl;

    return 0;
}