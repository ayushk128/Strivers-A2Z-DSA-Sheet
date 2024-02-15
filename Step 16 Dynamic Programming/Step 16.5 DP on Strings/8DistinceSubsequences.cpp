#include <bits/stdc++.h>
using namespace std;
int distinctSubsequencesRecursive(int i, int j, string s, string t)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (s[i] == t[j])
        return distinctSubsequencesRecursive(i - 1, j - 1, s, t) + distinctSubsequencesRecursive(i - 1, j, s, t);

    return distinctSubsequencesRecursive(i - 1, j, s, t);
}

int distinctSubsequencesMemoization(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = distinctSubsequencesMemoization(i - 1, j - 1, s, t, dp) + distinctSubsequencesMemoization(i - 1, j, s, t, dp);

    return dp[i][j] = distinctSubsequencesMemoization(i - 1, j, s, t, dp);
}

int distinctSubsequencesTabulation(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][m];
}

int distinctSubsequencesSpaceOptimization(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];

            else curr[j] = prev[j];
        }

        prev = curr;
    }

    return prev[m];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string t;
    cin >> t;

    int n = s.size();
    int m = t.size();

    cout << distinctSubsequencesRecursive(n, m, s, t) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << distinctSubsequencesMemoization(n, m, s, t, dp) << endl;

    cout << distinctSubsequencesTabulation(s, t) << endl;

    cout << distinctSubsequencesSpaceOptimization(s, t) << endl;
}