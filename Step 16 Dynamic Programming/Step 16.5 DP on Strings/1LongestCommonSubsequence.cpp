#include<bits/stdc++.h>
using namespace std;
int LCSRecursive(int i, int j, string &s1, string &s2) {
    if(i < 0 || j < 0) return 0;

    if(s1[i] == s2[j]) return 1 + LCSRecursive(i - 1, j - 1, s1, s2);

    return max(LCSRecursive(i - 1, j, s1, s2), LCSRecursive(i, j - 1, s1, s2));
}

int LCSMemoization(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1 + LCSMemoization(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(LCSMemoization(i - 1, j, s1, s2, dp), LCSMemoization(i, j - 1, s1, s2, dp));
}

// Memoization after shifting of indexes
// n = n - 1, 0 = -1, 1 = 0 and so on
int LCSMemoizationShiftedIndex(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + LCSMemoizationShiftedIndex(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(LCSMemoizationShiftedIndex(i - 1, j, s1, s2, dp), LCSMemoizationShiftedIndex(i, j - 1, s1, s2, dp));
}
int LCSTabulation(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int LCSSpaceOptimization(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1]) curr[j] = 1 + prev[j - 1];

            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    int n = s1.length();
    int m = s2.length();

    cout << LCSRecursive(n - 1, m - 1, s1, s2) << endl;

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << LCSMemoization(n - 1, m - 1, s1, s2, dp) << endl;


    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << LCSMemoizationShiftedIndex(n, m, s1, s2, dp) << endl;

    cout << LCSTabulation(s1, s2) << endl;
    cout << LCSSpaceOptimization(s1, s2) << endl;
    
}