#include<bits/stdc++.h>
using namespace std;

int numberOfIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count = 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> grid = {{0, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {0, 1, 1, 0}};

    // cout << numberOfEnclave(grid) << endl;
}