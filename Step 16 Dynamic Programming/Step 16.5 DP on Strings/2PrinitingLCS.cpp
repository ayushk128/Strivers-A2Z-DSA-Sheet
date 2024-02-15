#include<bits/stdc++.h>
using namespace std;
string printLCS(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];

    string s = "";
    for(int i = 0; i<len; i++) {
        s += "$";
    }

    int i = n;
    int j = m;
    int index = len - 1;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            s[index--] = s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else j--;
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << printLCS(s1, s2) << endl;
    
}