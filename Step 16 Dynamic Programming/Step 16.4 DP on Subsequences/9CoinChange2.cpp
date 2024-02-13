#include<bits/stdc++.h>
using namespace std;
int coinChangeRecursive(int index, vector<int> arr, int target) {
    if(index == 0) return target % arr[index] == 0;
    
    int notTake = coinChangeRecursive(index - 1, arr, target);
    int take = 0;
    if(arr[index] <= target) take = coinChangeRecursive(index, arr, target - arr[index]);

    return notTake + take;
}
int coinChangeMemoization(int index, vector<int> arr, int target, vector<vector<int>> &dp) {
    if(index == 0) return target % arr[index] == 0;
    
    if(dp[index][target] != -1) return dp[index][target];
    
    int notTake = coinChangeMemoization(index - 1, arr, target, dp);
    int take = 0;
    if(arr[index] <= target) take = coinChangeMemoization(index, arr, target - arr[index], dp);

    return dp[index][target] = notTake + take;
}

int coinChangeTabulation(vector<int> arr, int target) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int tar = 0; tar<=target; tar++) {
        if(tar % arr[0] == 0) dp[0][tar] = 1;
    }

    for(int ind = 1; ind<n; ind++) {
        for(int tar = 0; tar <= target; tar++) {
            int notTake = dp[ind - 1][tar];
            int take = 0;
            if(arr[ind] <= tar) take = dp[ind][tar - arr[ind]];

            dp[ind][tar] = notTake + take;
        }
    }

    return dp[n - 1][target];
}

int coinChangeSpaceOptimization(vector<int> arr, int target) {
    int n = arr.size();

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    for(int tar = 0; tar<=target; tar++) {
        if(tar % arr[0] == 0) prev[tar] = 1;
    }

    for(int ind = 1; ind<n; ind++) {
        for(int tar = 0; tar <= target; tar++) {
            int notTake = prev[tar];
            int take = 0;
            if(arr[ind] <= tar) take = curr[tar - arr[ind]];

            curr[tar] = notTake + take;
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

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << coinChangeRecursive(n - 1, arr, target) << endl;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << coinChangeMemoization(n - 1, arr, target, dp) << endl;

    cout << coinChangeTabulation(arr, target) << endl;

    cout << coinChangeSpaceOptimization(arr, target) << endl;
}