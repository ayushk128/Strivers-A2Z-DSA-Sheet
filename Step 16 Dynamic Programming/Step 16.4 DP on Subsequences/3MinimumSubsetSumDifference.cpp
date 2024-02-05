#include<bits/stdc++.h>
using namespace std;

bool partitionEqualTabulation(vector<int> &arr, int sum) {
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

void helper(int sum, vector<int> &arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end());
    
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