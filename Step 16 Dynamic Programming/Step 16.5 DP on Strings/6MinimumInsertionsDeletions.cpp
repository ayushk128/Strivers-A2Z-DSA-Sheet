#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubsequence(int i, int j, string s1, string s2) {
    if(i == 0 || j == 0) return 0;
    if(s1[i - 1] == s2[j - 1]) 
        return 1 + LongestCommonSubsequence(i - 1, j - 1, s1, s2);
    else return max(LongestCommonSubsequence(i - 1, j, s1, s2), LongestCommonSubsequence(i, j - 1, s1, s2));
}

int LongestCommonSubsequenceMemoization(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i - 1] == s2[j - 1]) 
        return dp[i][j] = 1 + LongestCommonSubsequenceMemoization(i - 1, j - 1, s1, s2, dp);
    else return dp[i][j] = max(LongestCommonSubsequenceMemoization(i - 1, j, s1, s2, dp), LongestCommonSubsequenceMemoization(i, j - 1, s1, s2, dp));
}

int LongestCommonSubsequenceTabulation(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int LongestCommonSubsequenceSpaceOptimization(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[m];
}

int minimumOperations(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    // int lenLCS = LongestCommonSubsequence(n, m, word1, word2);

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // int lenLCS = LongestCommonSubsequenceMemoization(n, m, word1, word2, dp);

    // int lenLCS = LongestCommonSubsequenceTabulation(word1, word2);

    int lenLCS = LongestCommonSubsequenceSpaceOptimization(word1, word2);

    int deletions = n - lenLCS;
    int insertions = m - lenLCS;

    return deletions + insertions;

    // or n + m - 2 * LCS;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1;
    cin >> s1;

    string s2;
    cin >> s2;

    cout << minimumOperations(s1, s2) << endl;

}