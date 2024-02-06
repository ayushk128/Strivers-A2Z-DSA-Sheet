#include<bits/stdc++.h>
using namespace std;

int minimumSubsetSumDifference(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));

    for(int i = 0; i<n; i++) {
        dp[i][0] = 0;
    }

    if(arr[0] <= sum)
        dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 1; tar <= sum; tar++) {
            bool notTake = dp[ind - 1][tar];
            bool take = false;
            if(arr[ind] <= tar) take = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = notTake || take;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i<=sum; i++) {
        if(dp[n - 1][i] == true) {
            int difference = abs(i - (sum - i));
            ans = min(ans, difference);
        }
    }
    return ans;
}

int helper(int sum, vector<int> &arr) {
    int n = arr.size();
    return minimumSubsetSumDifference(arr, sum);
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

    cout << helper(sum, arr) << endl;
}