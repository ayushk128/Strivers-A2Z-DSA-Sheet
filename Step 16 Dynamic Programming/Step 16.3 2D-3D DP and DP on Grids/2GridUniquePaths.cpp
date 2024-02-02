#include <bits/stdc++.h>
using namespace std;
int uniquePathsRecursive(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    int left = uniquePathsRecursive(i, j - 1);
    int up = uniquePathsRecursive(i - 1, j);

    return up + left;
}
int uniquePathsMemoizatioin(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = uniquePathsRecursive(i, j - 1);
    int up = uniquePathsRecursive(i - 1, j);

    return dp[i][j] = up + left;
}

int uniquePathTabulation(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int left = 0, up = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    up = dp[i - 1][j];

                dp[i][j] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePathSpaceOptimized(int m, int n)
{

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);

        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                int left = 0, up = 0;
                if (j > 0)
                    left = temp[j - 1];
                if (i > 0)
                    up = prev[j];

                temp[j] = left + up;
            }
        }
        prev = temp;
    }
    return prev[n - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m;
    int n;

    cin >> m >> n;

    cout << uniquePathsRecursive(m - 1, n - 1) << endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << uniquePathsMemoizatioin(m - 1, n - 1, dp) << endl;
    cout << uniquePathTabulation(m, n) << endl;
}