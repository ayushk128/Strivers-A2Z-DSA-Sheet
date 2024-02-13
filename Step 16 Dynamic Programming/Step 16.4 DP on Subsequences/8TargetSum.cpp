#include<bits/stdc++.h>
using namespace std;
int targetSumRecursive(int index, vector<int> arr, int sum) {
    if(index == 0) {
        if(sum == 0 && arr[index] == 0) return 2;
        if(sum == 0 || arr[index] == sum) return 1;
        return 0;
    }

    int notTake = targetSumRecursive(index - 1, arr, sum);
    int take = 0;
    if(arr[index] <= sum) take = targetSumRecursive(index - 1, arr, sum - arr[index]);

    return notTake + take;
}

int targetSumMemoization(int index, vector<int> arr, int sum, vector<vector<int>> &dp) {
    if(index == 0) {
        if(sum == 0 && arr[index] == 0) return 2;
        if(sum == 0 || arr[index] == sum) return 1;
        return 0;
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    int notTake = targetSumMemoization(index - 1, arr, sum, dp);
    int take = 0;
    if(arr[index] <= sum) take = targetSumMemoization(index - 1, arr, sum - arr[index], dp);

    return dp[index][sum] = notTake + take;
}

int targetSumTabulation(vector<int> arr, int sum) {
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 0; tar <= sum; tar++) {
            int notTake = dp[ind - 1][tar];
            int take = 0;
            if(arr[ind] <= tar) take = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = take + notTake;
        }
    }
    return dp[n - 1][sum];
}

int targetSumSpaceOptimization(vector<int> arr, int sum) {
    int n = arr.size();

    vector<int> prev(sum + 1, 0);
    vector<int> curr(sum + 1, 0);


    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 0; tar <= sum; tar++) {
            int notTake = prev[tar];
            int take = 0;
            if(arr[ind] <= tar) take = prev[tar - arr[ind]];

            curr[tar] = take + notTake;
        }
        prev = curr;
    }
    return prev[sum];
}
int helper(vector<int> arr, int d) {
    int n = arr.size();
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if(totSum - d < 0) return 0;
    if((totSum - d) % 2 == 1) return 0;

    int s2 = (totSum - d) / 2;

    // return targetSumRecursive(n - 1, arr, s2);

    // vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    // return targetSumMemoization(n - 1, arr, s2, dp);

    // return targetSumTabulation(arr, s2);

    return targetSumSpaceOptimization(arr, s2);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> arr[i];
    }

    int D;
    cin >> D;

    cout << helper(arr, D) << endl;
    
}