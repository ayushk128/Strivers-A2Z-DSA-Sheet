#include<bits/stdc++.h>
using namespace std;
int KnapSack(int ind, int W, vector<int> &wt, vector<int> &val) {
    if(ind == 0) {
        if(wt[ind] <= W) return val[ind];
        else return 0;
    }

    int notTake = KnapSack(ind - 1, W, wt, val);
    int take = INT_MIN;
    if(wt[ind] <= W) take = val[ind] + KnapSack(ind - 1, W - wt[ind], wt, val);

    return max(notTake, take);
}

int KnapSackMemoization(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(wt[ind] <= W) return val[ind];
        else return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = KnapSackMemoization(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind] <= W) take = val[ind] + KnapSackMemoization(ind - 1, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(notTake, take);
}

int KnapSackTabulation(int n, int W, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for(int w = wt[0]; w<=W; w++) {
        dp[0][w] = val[0];
    }

    for(int i = 1; i<n; i++) {
        for(int w = 0; w<=W; w++) {
            int notTake = dp[i - 1][w];
            int take = INT_MIN;
            if(wt[i] <= w) take = val[i] + dp[i - 1][W - wt[i]];

            dp[i][w] = max(notTake, take);
        }
    }
    return dp[n - 1][W];
}

int KnapSackSpaceOptimization(int n, int W, vector<int> &wt, vector<int> &val) {
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for(int w = wt[0]; w<=W; w++) {
        prev[w] = val[0];
    }

    for(int i = 1; i<n; i++) {
        for(int w = 0; w<=W; w++) {
            int notTake = prev[w];
            int take = INT_MIN;
            if(wt[i] <= w) take = val[i] + prev[W - wt[i]];

            curr[w] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[W];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 4;
    int W = 5;

    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};

    cout << KnapSack(n - 1, W, wt, val) << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << KnapSackMemoization(n - 1, W, wt, val, dp) << endl;

    cout << KnapSackTabulation(n, W, wt, val) << endl;

    cout << KnapSackSpaceOptimization(n, W, wt, val) << endl;
}