#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int numberOfMissingNumbers = arr[mid] - (mid + 1);

        if(numberOfMissingNumbers < k) low = mid + 1;
        else high = mid - 1;
    }
    // return low + k;
    return high + 1 + k;
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

    cout << findKthPositive(arr, k) << endl;
}