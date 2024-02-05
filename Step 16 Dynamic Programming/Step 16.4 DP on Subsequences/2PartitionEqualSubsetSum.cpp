#include<bits/stdc++.h>
using namespace std;
bool partitionEqualRecursive(int ind, vector<int> &arr, int target) {
    if(target == 0) return 0;
    if(ind == 0) return arr[0] == target;

    int notTake = partitionEqualRecursive(ind - 1, arr, target);
    int take = false;
    if(arr[ind] <= target) take = partitionEqualRecursive(ind - 1, arr, target - arr[ind]);

    return take || notTake;
}

bool partitionEqualMemoization(int ind, vector<int> &arr, int target, vector<vector<int>> &dp) {
    if(target == 0) return 0;
    if(ind == 0) return arr[0] == target;
    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = partitionEqualMemoization(ind - 1, arr, target, dp);
    int take = false;
    if(arr[ind] <= target) take = partitionEqualMemoization(ind - 1, arr, target - arr[ind], dp);

    return dp[ind][target] = take || notTake;
}

bool partitionEqualTabulation(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

    for(int i = 0; i<n; i++) {
        dp[i][0] = 0;
    }

    if(arr[0] <= target)
        dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 1; tar <= target; tar++) {
            bool notTake = dp[ind - 1][tar];
            bool take = false;
            if(arr[ind] <= tar) take = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = notTake || take;
        }
    }
    return dp[n - 1][target];
}

bool partitionEqualSpaceOptimization(vector<int> &arr, int target) {
    int n = arr.size();
    vector<bool> prev(target + 1, 0);
    vector<bool> cur(target + 1, 0);

    prev[0] = cur[0] = 0;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 1; tar <= target; tar++) {
            bool notTake = prev[tar];
            bool take = false;
            if(arr[ind] <= tar) take = prev[tar - arr[ind]];

            cur[tar] = notTake || take;
        }
        prev = cur;
    }
    return prev[target];
}

void helper(int sum, vector<int> &arr) {
    if(sum % 2 != 0) {
        cout << 0;
    }
    else {
        int n = arr.size();
        int target = sum / 2;

        cout << partitionEqualRecursive(n - 1, arr, target) << endl;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        cout << partitionEqualMemoization(n - 1, arr, target, dp) << endl;

        cout << partitionEqualTabulation(arr, target) << endl;

        cout << partitionEqualSpaceOptimization(arr, target) << endl;
    }
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

    int sum = accumulate(arr.begin(), arr.end(), 0);

    helper(sum, arr);
}