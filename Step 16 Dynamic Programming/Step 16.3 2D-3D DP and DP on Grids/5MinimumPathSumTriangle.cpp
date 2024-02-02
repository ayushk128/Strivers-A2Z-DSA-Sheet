#include <bits/stdc++.h>
using namespace std;
int minimumSumTriangleRecursive(int i, int j, int n, vector<vector<int>> &triangle)
{
    if (i == n - 1)
        return triangle[i][j];

    int down = triangle[i][j] + minimumSumTriangleRecursive(i + 1, j, n, triangle);
    int diagonal = triangle[i][j] + minimumSumTriangleRecursive(i + 1, j + 1, n, triangle);

    return min(down, diagonal);
}
int minimumSumTriangleMemoization(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + minimumSumTriangleMemoization(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + minimumSumTriangleMemoization(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(down, diagonal);
}
int minimumSumTriangleTabulation(int n, vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(n, vector<int>(n));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int minimumSumTriangleSpaceOptimization(int n, vector<vector<int>> &triangle)
{
    vector<int> front(n, 0);
    vector<int> curr(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }

    return front[0];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};
    int n = triangle.size();

    cout << minimumSumTriangleRecursive(0, 0, n, triangle) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << minimumSumTriangleMemoization(0, 0, n, triangle, dp) << endl;

    cout << minimumSumTriangleTabulation(n, triangle) << endl;

    cout << minimumSumTriangleSpaceOptimization(n, triangle) << endl;
}