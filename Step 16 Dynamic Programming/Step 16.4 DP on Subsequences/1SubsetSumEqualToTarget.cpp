#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int ind, vector<int> arr, int target) {
    if(target == 0) return 0;
    if(ind == 0) return arr[0] == target;

    bool notTake = subsetSum(ind - 1, arr, target);
    bool take = false;
    if(target >= arr[ind]) take = subsetSum(ind - 1, arr, target - arr[ind]);

    return notTake || take;
}

bool subsetSumMemoization(int ind, vector<int> arr, int target, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = subsetSumMemoization(ind - 1, arr, target, dp);
    bool take = false;
    if(target >= arr[ind]) take = subsetSumMemoization(ind - 1, arr, target - arr[ind], dp);

    return dp[ind][target] = notTake || take;
}

bool subsetSumTabulation(vector<int> arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for(int i = 0; i<n; i++) {
        dp[i][0] = true;
    }
    if(arr[0] <= target)
        dp[0][arr[0]] = true;

    for(int i = 1; i<n; i++) {
        for(int j = 1; j<=target; j++) {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if(j >= arr[i]) take = dp[i - 1][target - arr[i]];

            dp[i][j] = notTake || take;
        }
    }
    return dp[n - 1][target];
}

bool subsetSumSpaceOptimization(vector<int> arr, int target) {
    int n = arr.size();
    vector<bool> prev(target + 1, 0);
    vector<bool> curr(target + 1, 0);

    prev[0] = curr[0] = true;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int i = 1; i<n; i++) {
        for(int j = 1; j<=target; j++) {
            bool notTake = prev[target];
            bool take = false;
            if(j >= arr[i]) take = prev[target - arr[i]];

            curr[j] = notTake || take;
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

    cout << subsetSum(n - 1, arr, target) << endl;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << subsetSumMemoization(n - 1, arr, target, dp) << endl;

    cout << subsetSumTabulation(arr, target) << endl;

    cout << subsetSumSpaceOptimization(arr, target) << endl;
    
}