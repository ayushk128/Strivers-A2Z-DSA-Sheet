#include<bits/stdc++.h>
using namespace std;
int LongestPalindromicSubsequence(int i, int j, string &s1, string &s2) {
    if(i < 0 || j < 0) return 0;

    if(s1[i] == s2[j]) return 1 + LongestPalindromicSubsequence(i - 1, j - 1, s1, s2);

    return max(LongestPalindromicSubsequence(i - 1, j, s1, s2), LongestPalindromicSubsequence(i, j - 1, s1, s2));
}

int LongestPalindromicSubsequenceMemoization(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1 + LongestPalindromicSubsequenceMemoization(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(LongestPalindromicSubsequenceMemoization(i - 1, j, s1, s2, dp), LongestPalindromicSubsequenceMemoization(i, j - 1, s1, s2, dp));
}

// Memoization after shifting of indexes
// n = n - 1, 0 = -1, 1 = 0 and so on
int LongestPalindromicSubsequenceMemoizationShiftedIndex(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + LongestPalindromicSubsequenceMemoizationShiftedIndex(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(LongestPalindromicSubsequenceMemoizationShiftedIndex(i - 1, j, s1, s2, dp), LongestPalindromicSubsequenceMemoizationShiftedIndex(i, j - 1, s1, s2, dp));
}
int LongestPalindromicSubsequenceTabulation(string &s1, string &s2) {
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

int LongestPalindromicSubsequenceSpaceOptimization(string &s1, string &s2) {
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

    cin >> s1;

    string s2 = s1;

    reverse(s2.begin(), s2.end());

    int n = s1.length();


    cout << LongestPalindromicSubsequence(n - 1, n - 1, s1, s2) << endl;

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << LongestPalindromicSubsequenceMemoization(n - 1, n - 1, s1, s2, dp) << endl;


    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << LongestPalindromicSubsequenceMemoizationShiftedIndex(n, n, s1, s2, dp) << endl;

    cout << LongestPalindromicSubsequenceTabulation(s1, s2) << endl;
    cout << LongestPalindromicSubsequenceSpaceOptimization(s1, s2) << endl;
    
}