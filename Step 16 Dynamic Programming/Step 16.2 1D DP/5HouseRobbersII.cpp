#include<bits/stdc++.h>
using namespace std;
long long maxSum(int index, vector<long long> arr) {
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    long long pick = arr[index] + maxSum(index - 2, arr);
    long long notPick = maxSum(index - 1, arr);

    return max(pick, notPick);
}

long long solve(int n, vector<long long> arr) {
    vector<long long> arr1;
    vector<long long> arr2;

    if(n == 1) return arr[0];

    for(int i = 0; i<n; i++) {
        if(i != 0) arr1.push_back(arr[i]);
        if(i != n - 1) arr2.push_back(arr[i]);
    }

    long long ans1 = maxSum(n - 2, arr1);
    long long ans2 = maxSum(n - 2, arr2);
    return max(ans1, ans2);

    // vector<int> dp(n, -1);
    // cout << maxSumMemoization(n - 1, arr, dp) << endl;

    // cout << maxSumTabulation(n, arr) << endl;

    // cout << maxSumSpaceOptimization(n, arr) << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << solve(n, arr) << endl;
}