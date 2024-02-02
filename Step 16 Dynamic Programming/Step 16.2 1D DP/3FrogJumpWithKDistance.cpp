#include<bits/stdc++.h>
using namespace std;
int frogJump(int index, vector<int> &height, int k) {
    if(index == 0) return 0;

    int minEnergy = INT_MAX;

    for(int i = 1; i<=k; i++) {
        if(index - i >= 0) {
            int currentEnergy = frogJump(index - i, height, k) + abs(height[index] - height[index - i]);
            minEnergy = min(minEnergy, currentEnergy);
        }
    }

    return minEnergy;
}
int frogJumpMemoization(int index, vector<int> &height, int k, vector<int> &dp) {
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int minEnergy = INT_MAX;

    for(int i = 1; i<=k; i++) {
        if(index - i >= 0) {
            int currentEnergy = frogJump(index - i, height, k) + abs(height[index] - height[index - i]);
            minEnergy = min(minEnergy, currentEnergy);
        }
    }

    return dp[index] = minEnergy;
}
int frogJumpTabulation(int n, int k, vector<int> &height) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i<n; i++) {
        int minEnergy = INT_MAX;
        for(int j = 1; j<=k; j++) {
            if(i - j >= 0) {
                int currentEnergy = dp[i - j] + abs(height[i] - height[i - j]);
                minEnergy = min(minEnergy, currentEnergy);
            }
        }
        dp[i] = minEnergy;
    }
    return dp[n - 1];
}

int main() { 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> height(n);
    for(int i = 0; i<n; i++) {
        cin >> height[i];
    }

    int k;
    cin >> k;

    cout << frogJump(n - 1, height, k) << endl;

    vector<int> dp(n, -1);
    frogJumpMemoization(n - 1, height, k, dp);
    cout << dp[n - 1] << endl;

    cout << frogJumpTabulation(n, k, height) << endl;
}