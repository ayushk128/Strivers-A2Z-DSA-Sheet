#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubstring(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = INT_MIN;

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1]) {

                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}
int LongestCommonSubstringSpaceOptimized(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    int ans = INT_MIN;

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1]) {

                int val = 1 + prev[j - 1];
                curr[j] = val;
                ans = max(ans, val);
            }
            else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << LongestCommonSubstring(s1, s2) << endl;

    cout << LongestCommonSubstringSpaceOptimized(s1, s2) << endl;
    
}