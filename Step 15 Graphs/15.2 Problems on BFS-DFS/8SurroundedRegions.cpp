#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int delRow[], int delCol[]) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();


    for(int i = 0; i<4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 'O') {
            dfs(nRow, nCol, grid, vis, delRow, delCol);
        }
    }
}
void SurroundRegion(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if(grid[i][j] == 'O' && vis[i][j] == 0) {
                    dfs(i, j, grid, vis, delRow, delCol);
                }
            }
        }
    }

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] == 'O' && vis[i][j] == 0) {
                grid[i][j] = 'X';
            }
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'X', 'O', 'X', 'O'},
                                    {'X', 'O', 'X', 'O', 'X'}, {'O', 'O', 'X', 'X', 'X'}};

    SurroundRegion(grid);
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }   
}