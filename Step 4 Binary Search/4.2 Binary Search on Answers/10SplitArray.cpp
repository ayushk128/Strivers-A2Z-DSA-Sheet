#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &arr, int n, int sum) {
    int noOfPartitions = 1;
    int prevSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(arr[i] + prevSum <= sum) {
            prevSum += arr[i];
        }
        else {
            noOfPartitions++;
            prevSum = arr[i];
        }
    } 
    return noOfPartitions;
}
int splitArray(vector<int> &arr, int k) {
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        int noOfPartitions = countPartitions(arr, n, mid);
        
        if(noOfPartitions > k) {
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

    cout << splitArray(arr, k) << endl;
}