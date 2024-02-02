//Same question - House Robbers I
#include<bits/stdc++.h>
using namespace std;
int maxSum(int index, vector<int> arr) {
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    int pick = arr[index] + maxSum(index - 2, arr);
    int notPick = maxSum(index - 1, arr);

    return max(pick, notPick);
}

int maxSumMemoization(int n, vector<int> arr, vector<int> &dp) {
    if(n == 0) return arr[n];
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    int pick = arr[n] + maxSumMemoization(n - 2, arr, dp);
    int notPick = maxSumMemoization(n - 1, arr, dp);

    return dp[n] = max(pick, notPick);
}

int maxSumTabulation(int n, vector<int> arr) {
    vector<int> dp(n, 0);

    dp[0] = arr[0];
    for(int i = 1; i<n; i++) {
        int pick = arr[i];
        if(i > 1) 
            pick += dp[i - 2];
        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

int maxSumSpaceOptimization(int n, vector<int> arr) {
    int prev = arr[0];
    int prev2 = 0;
    for(int i = 1; i<n; i++) {
        int pick = arr[i];
        if(i > 1)
            pick += prev2;
        int notPick = prev;

        int curr_i = max(pick, notPick);

        prev2 = prev;
        prev = curr_i;
    }
    return prev;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << maxSum(n - 1, arr) << endl;

    vector<int> dp(n, -1);
    cout << maxSumMemoization(n - 1, arr, dp) << endl;

    cout << maxSumTabulation(n, arr) << endl;

    cout << maxSumSpaceOptimization(n, arr) << endl;

}