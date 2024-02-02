#include<bits/stdc++.h>
using namespace std;
int numberOfWaysRecursive(int n) {
    if(n == 0 || n == 1) return 1;

    return numberOfWaysRecursive(n - 1) + numberOfWaysRecursive(n - 2);
}

int numberOfWaysMemoization(int n, vector<int> &dp) {
    if(n == 0 || n == 1) return 1;
    
    if(dp[n] != -1) return dp[n];
    return dp[n] = numberOfWaysMemoization(n - 1, dp) + numberOfWaysMemoization(n - 2, dp);
}

int numberOfWaysTabulation(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int numberOfWaysSpaceOptimized(int n) {
    int prev2 = 1;
    int prev = 1;
    for(int i = 2; i<=n; i++) {
        int curri = prev2 + prev;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
int main() { 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << numberOfWaysRecursive(n) << endl;

    vector<int> dp(n + 1, -1);

    cout << numberOfWaysMemoization(n, dp) << endl;

    cout << numberOfWaysTabulation(n) << endl;

    cout << numberOfWaysSpaceOptimized(n) << endl;
}