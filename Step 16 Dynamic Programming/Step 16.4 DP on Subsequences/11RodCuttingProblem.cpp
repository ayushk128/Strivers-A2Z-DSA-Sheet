#include<bits/stdc++.h>
using namespace std;
int rodCuttingRecursive(int index, vector<int> &arr, int n) {
    if(index == 0) {
        return arr[0] * n;
    }

    int notTake = rodCuttingRecursive(index - 1, arr, n);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= n) take = arr[index] + rodCuttingRecursive(index, arr, n - rodLength);

    return max(notTake, take);
}

int rodCuttingMemoization(int index, vector<int> &arr, int n, vector<vector<int>> &dp) {
    if(index == 0) {
        return arr[0] * n;
    }
    if(dp[index][n] != -1) return dp[index][n];

    int notTake = rodCuttingMemoization(index - 1, arr, n, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= n) take = arr[index] + rodCuttingMemoization(index, arr, n - rodLength, dp);

    return dp[index][n] = max(notTake, take);
}

int rodCuttingTabulation(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    for(int i = 0; i<=n; i++) {
        dp[0][i] = arr[0] * i;
    }
    for(int ind = 1; ind<n; ind++) {
        for(int len = 0; len<=n; len++) {
            int notTake = dp[ind - 1][len];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= len) take = arr[ind] + dp[ind][len - rodLength];

            dp[ind][len] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

int rodCuttingSpaceOptimization(vector<int> &arr, int n) {
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for(int i = 0; i<=n; i++) {
        prev[i] = arr[0] * i;
    }
    for(int ind = 1; ind<n; ind++) {
        for(int len = 0; len<=n; len++) {
            int notTake = prev[len];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= len) take = arr[ind] + curr[len - rodLength];

            curr[len] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << rodCuttingRecursive(n - 1, arr, n) << endl;

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << rodCuttingMemoization(n - 1, arr, n, dp) << endl;

    cout << rodCuttingTabulation(arr, n) << endl;

    cout << rodCuttingSpaceOptimization(arr, n) << endl;
    
}