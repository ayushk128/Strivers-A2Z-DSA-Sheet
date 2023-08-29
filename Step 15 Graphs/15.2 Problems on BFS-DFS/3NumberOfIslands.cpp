#include<bits/stdc++.h>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();


    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int delRow = -1; delRow <= 1; delRow++) {
            for(int delCol = -1; delCol <= 1; delCol++) {
                int nRow = r + delRow;
                int nCol = c + delCol;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                    && vis[nRow][nCol] != 1 && grid[nRow][nCol] == 1) {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
            }
        }
    }
}
int NumberOfIslands(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count = 0;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(vis[row][col] != 1 && grid[row][col] == 1) {
                count++;
                bfs(row, col, grid, vis);
            }
        }
    }
    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};

    cout << NumberOfIslands(grid)<<endl;
}