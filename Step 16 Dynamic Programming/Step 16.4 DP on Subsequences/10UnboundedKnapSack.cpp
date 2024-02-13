#include <bits/stdc++.h>
using namespace std;
int unboundedKnapSackRecursive(int index, int W, vector<int> &wt, vector<int> &val)
{

    if (index == 0)
    {
        return (W / wt[index]) * val[index];
    }

    int notPick = unboundedKnapSackRecursive(index - 1, W, wt, val);
    int pick = 0;
    if (wt[index] <= W)
        pick = val[index] + unboundedKnapSackRecursive(index, W - wt[index], wt, val);

    return max(notPick, pick);
}

int unboundedKnapSackMemoization(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{

    if (index == 0)
    {
        return (W / wt[index]) * val[index];
    }

    if(dp[index][W] != -1) return dp[index][W];

    int notPick = unboundedKnapSackMemoization(index - 1, W, wt, val, dp);
    int pick = 0;
    if (wt[index] <= W)
        pick = val[index] + unboundedKnapSackMemoization(index, W - wt[index], wt, val, dp);

    return dp[index][W] = max(notPick, pick);
}

int unboundedKnapSackTabulation(int W, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    for(int i = 0; i<=W; i++) {
        dp[0][i] = (i / wt[0]) * val[0];
    }

    for(int i = 1; i<n; i++) {
        for(int w = 0; w<=W; w++) {
            int notPick = dp[i - 1][w];
            int pick = INT_MIN;
            if(wt[i] <= w) pick = val[i] + dp[i][w - wt[i]];

            dp[i][w] = max(notPick, pick);
        }
    }
    return dp[n - 1][W];
}

int unboundedKnapSackSpaceOptimization(int W, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for(int i = 0; i<=W; i++) {
        prev[i] = (i / wt[0]) * val[0];
    }

    for(int i = 1; i<n; i++) {
        for(int w = 0; w<=W; w++) {
            int notPick = prev[w];
            int pick = INT_MIN;
            if(wt[i] <= w) pick = val[i] + curr[w - wt[i]];

            curr[w] = max(notPick, pick);
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();

    cout << unboundedKnapSackRecursive(n - 1, W, wt, val) << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << unboundedKnapSackMemoization(n - 1, W, wt, val, dp) << endl;

    cout << unboundedKnapSackTabulation(W, wt, val) << endl;

    cout << unboundedKnapSackSpaceOptimization(W, wt, val) << endl;
}