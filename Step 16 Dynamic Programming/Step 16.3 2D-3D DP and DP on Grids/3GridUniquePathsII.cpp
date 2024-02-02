#include <bits/stdc++.h>
using namespace std;
int uniquePathsRecursive(int n, int m, vector<vector<int>> &maze)
{
    if (n > 0 && m > 0 && maze[n][m] == -1)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;

    int left = uniquePathsRecursive(n, m - 1, maze);
    int up = uniquePathsRecursive(n - 1, m, maze);

    return left + up;
}

int uniquePathsMemoization(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    if (n > 0 && m > 0 && maze[n][m] == -1)
        return 0;
    if (n == 0 && m == 0)
        return 1;
    if (n < 0 || m < 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int left = uniquePathsMemoization(n, m - 1, maze, dp);
    int up = uniquePathsMemoization(n - 1, m, maze, dp);

    return dp[n][m] = left + up;
}

int uniquePathsTabulation(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    up = dp[i - 1][j];

                dp[i][j] = left + up;
            }
        }
    }
    return dp[n - 1][m - 1];
}

int uniquePathsSpaceOptimization(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == -1)
                temp[j] = 0;
            else if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (j > 0)
                    left = temp[j - 1];
                if (i > 0)
                    up = prev[j];

                temp[j] = left + up;
            }
        }
            prev = temp;
    }
    return prev[m - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }

    cout << uniquePathsRecursive(n - 1, m - 1, maze) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << uniquePathsMemoization(n - 1, m - 1, maze, dp) << endl;

    cout << uniquePathsTabulation(n, m, maze) << endl;

    cout << uniquePathsSpaceOptimization(n, m, maze) << endl;
}