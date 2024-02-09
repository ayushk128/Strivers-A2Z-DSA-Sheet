#include<bits/stdc++.h>
using namespace std;
int minimumCoins(int ind, vector<int> coins, int target) {
    if(ind == 0) {
        if(target % coins[ind] == 0) {
            return target / coins[ind];
        }
        else return 1e9;
    }
    int notTake = minimumCoins(ind - 1, coins, target);
    int take = INT_MAX;
    if(coins[ind] <= target) take = 1 + minimumCoins(ind, coins, target - coins[ind]);

    return min(notTake, take);
}

int minimumCoinsMemoization(int ind, vector<int> coins, int target, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(target % coins[ind] == 0) {
            return target / coins[ind];
        }
        else return INT_MAX;
    }
    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = minimumCoinsMemoization(ind - 1, coins, target, dp);
    int take = INT_MAX;
    if(coins[ind] <= target) take = 1 + minimumCoinsMemoization(ind, coins, target - coins[ind], dp);

    return dp[ind][target] = min(notTake, take);
}

int minimumCoinsTabulation(int n, vector<int> coins, int target) {
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int i = 0; i<=target; i++) {
        if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        else dp[0][i] = 1e9;    
    }

    for(int ind = 1; ind<n; ind++) {
        for(int tar = 0; tar<=target; tar++) {
            int notTake = dp[ind - 1][tar];
            int take = 1e9;
            if(coins[ind] <= tar) take = 1 + dp[ind][tar - coins[ind]];

            dp[ind][tar] = min(take, notTake);
        }
    }
    return dp[n - 1][target];
}

int minimumCoinsSpaceOptimization(int n, vector<int> coins, int target) {
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    for(int i = 0; i<=target; i++) {
        if(i % coins[0] == 0) prev[i] = i / coins[0];
        else prev[i] = 1e9;    
    }

    for(int ind = 1; ind<n; ind++) {
        for(int tar = 0; tar<=target; tar++) {
            int notTake = prev[tar];
            int take = 1e9;
            if(coins[ind] <= tar) take = 1 + curr[tar - coins[ind]];

            curr[tar] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[target];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> coins[i];
    }

    int target;
    cin >> target;

    cout << minimumCoins(n - 1, coins, target) << endl;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << minimumCoinsMemoization(n - 1, coins, target, dp) << endl;


    cout << minimumCoinsTabulation(n, coins, target) << endl;

    cout << minimumCoinsSpaceOptimization(n, coins, target) << endl;
    
}