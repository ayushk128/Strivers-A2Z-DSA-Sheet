#include<bits/stdc++.h>
using namespace std;
int numberOfSubsets(int ind, int sum, vector<int> arr) {
    if(ind == 0) {
        if(sum == 0 && arr[ind] == 0) return 2;
        if(sum == 0 || arr[ind] == sum) return 1;
        return 0;
    }

    int notTake = numberOfSubsets(ind - 1, sum, arr);
    int take = 0;
    if(arr[ind] <= sum) take = numberOfSubsets(ind - 1, sum - arr[ind], arr);

    return notTake + take;
}

int numberOfSubsetsMemoization(int ind, int sum, vector<int> arr, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(sum == 0 && arr[ind] == 0) return 2;
        if(sum == 0 || arr[ind] == sum) return 1;
        return 0;
    }

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int notTake = numberOfSubsetsMemoization(ind - 1, sum, arr, dp);
    int take = 0;
    if(arr[ind] <= sum) take = numberOfSubsetsMemoization(ind - 1, sum - arr[ind], arr, dp);

    return dp[ind][sum] = notTake + take;
}

// int numberOfSubsetsTabulation(int sum, vector<int> arr) {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

//     for(int i = 0; i<n; i++) {
//         dp[i][0] = 1;
//     }
// }

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << numberOfSubsets(n - 1, k, arr) << endl;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << numberOfSubsetsMemoization(n - 1, k, arr, dp) << endl;


}