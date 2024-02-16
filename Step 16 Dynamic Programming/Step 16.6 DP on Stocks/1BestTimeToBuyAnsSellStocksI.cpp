#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int mini = prices[0];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - mini;
        ans = max(ans, cost);

        mini = min(mini, prices[i]);
    }

    return ans;
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxProfit(arr) << endl;
    
}