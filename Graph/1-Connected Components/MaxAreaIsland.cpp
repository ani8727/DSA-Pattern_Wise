// Max Area of Island  - 695

#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
    grid[i][j] = 0;
    int area = 1;

    for (int d = 0; d < 4; d++) {
        int x = i + dx[d];
        int y = j + dy[d];

        if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
            area += dfs(grid, x, y, m, n);
        }
    }
    return area;
}

int maxArea(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfs(grid, i, j, m, n));
            }
        }
    }
    return maxArea;
}

int main(){
    int rows,cols;
    cin>>rows>>cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>grid[i][j];
        }
    }

    cout<<"Islands: "<<maxArea(grid)<<endl;

    return 0;
}