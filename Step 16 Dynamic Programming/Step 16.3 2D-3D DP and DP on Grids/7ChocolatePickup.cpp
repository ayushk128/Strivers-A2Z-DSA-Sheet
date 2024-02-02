#include <bits/stdc++.h>
using namespace std;
int maximumChocolateRecursive(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return matrix[i][j1];
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    int maxi = INT_MIN;

    // In total 9 combinations, outer loop is for Alice and inner loop is for bob
    for (int delj1 = -1; delj1 <= 1; delj1++)
    {
        for (int delj2 = -1; delj2 <= 1; delj2++)
        {
            int ans;
            if (j1 == j2)
            {
                ans = matrix[i][j1] + maximumChocolateRecursive(i + 1, j1 + delj1, j2 + delj2, n, m, matrix);
            }
            else
            {
                ans = matrix[i][j1] + matrix[i][j2] + maximumChocolateRecursive(i + 1, j1 + delj1, j2 + delj2, n, m, matrix);
            }
            maxi = max(maxi, ans);
        }
    }
    return maxi;
}
int maximumChocolateMemoization(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    if (i == n - 1)
    {
        if (j1 == j2)
            return matrix[i][j1];
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    int maxi = INT_MIN;

    // In total 9 combinations, outer loop is for Alice and inner loop is for bob
    for (int delj1 = -1; delj1 <= 1; delj1++)
    {
        for (int delj2 = -1; delj2 <= 1; delj2++)
        {
            int ans;
            if (j1 == j2)
            {
                ans = matrix[i][j1] + maximumChocolateMemoization(i + 1, j1 + delj1, j2 + delj2, n, m, matrix, dp);
            }
            else
            {
                ans = matrix[i][j1] + matrix[i][j2] + maximumChocolateMemoization(i + 1, j1 + delj1, j2 + delj2, n, m, matrix, dp);
            }
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << maximumChocolateRecursive(0, 0, m - 1, n, m, matrix) << endl;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << maximumChocolateMemoization(0, 0, m - 1, n, m, matrix, dp) << endl;
}