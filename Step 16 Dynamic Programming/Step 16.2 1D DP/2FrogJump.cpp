#include<bits/stdc++.h>
using namespace std;
int frogJump(int index, vector<int> &height) {
    if(index == 0) return 0;

    int singleJump = frogJump(index - 1, height) + abs(height[index] - height[index - 1]);
    int doubleJump = INT_MAX;
    if(index > 1) 
        doubleJump = frogJump(index - 2, height) + abs(height[index] - height[index - 2]);
    
    return min(singleJump, doubleJump);
}

int frogJumpMemoization(int index, vector<int> &height, vector<int> &dp) {
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int singleJump = frogJumpMemoization(index - 1, height, dp) + abs(height[index] - height[index - 1]);
    int doubleJump = INT_MAX;
    if(index > 1) 
        doubleJump = frogJumpMemoization(index - 2, height, dp) + abs(height[index] - height[index - 2]);
    
    return dp[index] = min(singleJump, doubleJump);
}

int frogJumpTabulation(int n, vector<int> &height) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i<n; i++) {
        int singleJump = dp[i - 1] + abs(height[i] - height[i - 1]);
        int doubleJump = INT_MAX;
        if(i > 1)
            doubleJump = dp[i - 2] + abs(height[i] - height[i - 2]);
        
        dp[i] = min(singleJump, doubleJump);
    }
    return dp[n - 1];
}

int frogJumpSpaceOptimized(int n, vector<int> &height) {
    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i<n; i++) {
        int singleJump = prev + abs(height[i] - height[i - 1]);
        int doubleJump = INT_MAX;
        if(i > 1)
            doubleJump = prev2 + abs(height[i] - height[i - 2]);
        
        int curri = min(singleJump, doubleJump);

        prev2 = prev;
        prev = curri;
    }
    return prev;
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

    cout << frogJump(n - 1, height) << endl;

    vector<int> dp(n, -1);
    frogJumpMemoization(n - 1, height, dp);
    cout << dp[n - 1] << endl;

    cout << frogJumpTabulation(n, height) << endl;
    cout << frogJumpSpaceOptimized(n, height) << endl;
}