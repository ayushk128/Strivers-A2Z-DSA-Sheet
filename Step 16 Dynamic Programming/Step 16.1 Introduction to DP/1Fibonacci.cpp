#include<bits/stdc++.h>
using namespace std;

int fibonacciRecursion(int n) {
    if(n <= 1) return n;
    
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciMemoization(int n, vector<int> &dp) {
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fibonacciMemoization(n - 1, dp) + fibonacciMemoization(n - 2, dp);
}

int fibonacciTabulation(int n) {
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<=n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibonacciSpaceOptimized(int n) {
    int prev2 = 0;
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

    cout << fibonacciRecursion(n) << endl;


    vector<int> dp(n + 1, -1);

    cout << fibonacciMemoization(n, dp) << endl;
    
    cout << fibonacciTabulation(n) << endl;
    cout << fibonacciSpaceOptimized(n) << endl;
}