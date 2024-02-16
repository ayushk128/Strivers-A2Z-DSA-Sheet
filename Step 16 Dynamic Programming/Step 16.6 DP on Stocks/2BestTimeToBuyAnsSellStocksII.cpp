#include<bits/stdc++.h>
using namespace std;
int maxProfitRecursive(int index, int buy, int n, vector<int> &prices) {
    if(index == n) {
        return 0;
    }

    int profit = 0;
    if(buy) {
        profit = max(-prices[index] + maxProfitRecursive(index + 1, 0, n, prices), 0 + maxProfitRecursive(index + 1, 1, n, prices));
    }
    else {
        profit = max(prices[index] + maxProfitRecursive(index + 1, 1, n, prices), 0 + maxProfitRecursive(index + 1, 0, n, prices));
    }

    return profit;
}

int maxProfitMemoization(int index, int buy, int n, vector<int> &prices, vector<vector<int>> &dp) {
    if(index == n) {
        return 0;
    }

    if(dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if(buy) {
        profit = max(-prices[index] + maxProfitMemoization(index + 1, 0, n, prices, dp), 0 + maxProfitMemoization(index + 1, 1, n, prices, dp));
    }
    else {
        profit = max(prices[index] + maxProfitMemoization(index + 1, 1, n, prices, dp), 0 + maxProfitMemoization(index + 1, 0, n, prices, dp));
    }

    return dp[index][buy] = profit;
}

int maxProfitTabulation(vector<int> &prices) {
    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for(int index = n - 1; index>=0; index--) {
        for(int buy = 0; buy<=1; buy++) {
            int profit = 0;
            if(buy) {
                profit = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            }
            else {
                profit = max(prices[index] + dp[index + 1][1], 0 + dp[index + 1][0]);

            }

            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfitSpaceOptimization(vector<int> &prices) {
    int n = prices.size();

    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;

    for(int index = n - 1; index>=0; index--) {
        for(int buy = 0; buy<=1; buy++) {
            int profit = 0;
            if(buy) {
                profit = max(-prices[index] + ahead[0], 0 + ahead[1]);
            }
            else {
                profit = max(prices[index] + ahead[1], 0 + ahead[0]);

            }

            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
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

    cout << maxProfitRecursive(0, 1, n, arr) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    cout << maxProfitMemoization(0, 1, n, arr, dp) << endl;

    cout << maxProfitTabulation(arr) << endl;

    cout << maxProfitSpaceOptimization(arr) << endl;
    
}