#include <bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int> &arr, int dist, int k) {
    int last = arr[0];
    int countCows = 1;

    for(int i = 1; i<arr.size(); i++) {
        if(arr[i] - last >= dist) {
            countCows++;
            last = arr[i];
        }
        if(countCows >= k) return true;
    }

    return false;
}
int aggressiveCows(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[n - 1] - arr[0];

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canWePlace(arr, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << aggressiveCows(arr, k) << endl;
}