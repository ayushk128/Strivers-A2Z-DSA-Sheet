// Do tabulation and space optimization - Remaining
#include <bits/stdc++.h>
using namespace std;
bool isMatchRecursive(int i, int j, string &text, string &pattern) {
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >=0) {
        for(int k = 0; k<=j; k++) {
            if(pattern[k] != '*') return false;
        }
        return true;
    }

    if(text[i] == pattern[j] || pattern[j] == '?') return isMatchRecursive(i - 1, j - 1, text, pattern);
    else if(pattern[j] == '*')
        return isMatchRecursive(i, j - 1, text, pattern) || isMatchRecursive(i - 1, j, text, pattern); 
}

// bool isMatchMemoization(int i, int j, string &text, string &pattern, vector<vector<int>> &dp) {
//     if(i < 0 && j < 0) return true;
//     if(j < 0 && i >= 0) return false;
//     if(i < 0 && j >=0) {
//         for(int k = 0; k<=j; k++) {
//             if(pattern[k] != '*') return false;
//         }
//         return true;
//     }

//     if(dp[i][j] != -1) return dp[i][j];

//     if(text[i] == pattern[j] || pattern[j] == '?') return dp[i][j] = isMatchMemoization(i - 1, j - 1, text, pattern, dp);
//     else if(pattern[j] == '*')
//         return dp[i][j] = isMatchMemoization(i, j - 1, text, pattern, dp) || isMatchMemoization(i - 1, j, text, pattern, dp); 
// }

// 1-Based indexing
bool isMatchMemoization(int i, int j, string &text, string &pattern, vector<vector<int>> &dp) {
    if(i == 0 && j == 0) return true;
    if(j == 0 && i > 0) return false;
    if(i == 0 && j > 0) {
        for(int k = 1; k<=j; k++) {
            if(pattern[k - 1] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') return dp[i][j] = isMatchMemoization(i - 1, j - 1, text, pattern, dp);
    else if(pattern[j - 1] == '*')
        return dp[i][j] = isMatchMemoization(i, j - 1, text, pattern, dp) || isMatchMemoization(i - 1, j, text, pattern, dp); 

    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    cin >> text;

    string pattern;
    cin >> pattern;

    int n = text.size();
    int m = pattern.size();

    cout << isMatchRecursive(n - 1, m - 1, text, pattern) << endl;

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << isMatchMemoization(n - 1, m - 1, text, pattern, dp) << endl;

    // 1-Based indexing
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << isMatchMemoization(n, m, text, pattern, dp) << endl;
}