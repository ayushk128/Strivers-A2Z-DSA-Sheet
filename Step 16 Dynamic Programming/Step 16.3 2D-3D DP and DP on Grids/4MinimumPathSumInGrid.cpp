#include <bits/stdc++.h>
using namespace std;
int minimumPathSumRecursive(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    int up = grid[i][j] + minimumPathSumRecursive(i - 1, j, grid);
    int left = grid[i][j] + minimumPathSumRecursive(i, j - 1, grid);

    return min(up, left);
}

int minimumPathSumMemoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + minimumPathSumMemoization(i - 1, j, grid, dp);
    int left = grid[i][j] + minimumPathSumMemoization(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minimumPathSumTabulation(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }
                else
                    up = 1e9;

                if (j > 0)
                {
                    left = grid[i][j] + dp[i][j - 1];
                }
                else
                    left = 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int minimumPathSumSpaceOptimization(int n, int m, vector<vector<int>> &grid)
{
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);

        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
            }
            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                {
                    up = grid[i][j] + prev[j];
                }
                else
                    up = 1e9;

                if (j > 0)
                {
                    left = grid[i][j] + curr[j - 1];
                }
                else
                    left = 1e9;

                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << minimumPathSumRecursive(n - 1, m - 1, grid) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minimumPathSumMemoization(n - 1, m - 1, grid, dp) << endl;

    cout << minimumPathSumTabulation(n, m, grid) << endl;

    cout << minimumPathSumSpaceOptimization(n, m, grid) << endl;
}