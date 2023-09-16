#include<bits/stdc++.h>
using namespace std;
void numberOfIslandsUtil(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int n, int m) {
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int rowCordinates = -1; rowCordinates<=1; rowCordinates++) {
            for(int colCordinates = -1; colCordinates<=1; colCordinates++) {
                int nRow = r + rowCordinates;
                int nCol = c + colCordinates;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}

int numberOfIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count = 0;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                count++;
                numberOfIslandsUtil(i, j, grid, vis, n, m);
            }
        }
    }
    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 1}};

    cout << numberOfIslands(grid) << endl;
}