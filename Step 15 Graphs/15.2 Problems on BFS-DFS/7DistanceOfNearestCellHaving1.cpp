#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> distanceUsingBFS(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] == 1) {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        distance[row][col] = steps;
        q.pop();

        for(int i = 0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0) {
                vis[nRow][nCol] = 1;
                q.push({{nRow, nCol}, steps + 1});
            }
        }

    }

    return distance;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> grid = {{1, 0, 1}, {1, 1, 0}, {1, 0, 0}};

    vector<vector<int>> ans = distanceUsingBFS(grid);

    int n = ans.size();
    int m = ans[0].size();

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}