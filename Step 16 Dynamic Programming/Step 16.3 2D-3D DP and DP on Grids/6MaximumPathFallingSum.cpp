#include <bits/stdc++.h>
using namespace std;
int minimumPathSumRecursive(int i, int j, int m, vector<vector<int>> &matrix)
{

    if (j < 0 || j >= m)
        return INT_MIN;
    if (i == 0)
        return matrix[0][j];

    int up = matrix[i][j] + minimumPathSumRecursive(i - 1, j, m, matrix);
    int leftDiagonal = matrix[i][j] + minimumPathSumRecursive(i - 1, j - 1, m, matrix);
    int rightDiagonal = matrix[i][j] + minimumPathSumRecursive(i - 1, j + 1, m, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}
int minimumPathSumMemoization(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    if (j < 0 || j >= m)
        return INT_MIN;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + minimumPathSumMemoization(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + minimumPathSumMemoization(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + minimumPathSumMemoization(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}
int minimumPathSumTabulation(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j > 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal = -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal = -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, dp[n - 1][j]);
    }

    return ans;
}

int minimumPathSumSpaceOptimization(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);

        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j > 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal = -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal = -1e9;

            curr[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, prev[j]);
    }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int temp = minimumPathSumRecursive(n - 1, j, m, matrix);
        ans = max(ans, temp);
    }
    cout << ans << endl;

    ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int j = 0; j < m; j++)
    {
        int temp = minimumPathSumMemoization(n - 1, j, m, matrix, dp);
        ans = max(ans, temp);
    }
    cout << ans << endl;

    cout << minimumPathSumTabulation(matrix) << endl;
    
    
    cout << minimumPathSumSpaceOptimization(matrix) << endl;
}