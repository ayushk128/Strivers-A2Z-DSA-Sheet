#include <bits/stdc++.h>
using namespace std;
long long noOfPainters(vector<int> &arr, int n, long long givenHours) {
    int noOfPainters = 1;
    int prevHours = 0;
    
    for(int i = 0; i<n; i++) {
        if(arr[i] + prevHours <= givenHours) {
            prevHours += arr[i];
        }
        else {
            prevHours = arr[i];
            noOfPainters++;
        }
    }
    return noOfPainters;
}
long long minTime(vector<int> &arr, int n, int k)
{
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0);
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        
        if(noOfPainters(arr, n, mid) > k) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return low;
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

    cout << minTime(arr, n, k) << endl;
}