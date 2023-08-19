#include<bits/stdc++.h>
using namespace std;
int PeakElement(int *arr, int n) {
    
    // Check for single element
    if(n == 1) return 0;

    // Check for 1st element
    if(arr[0] > arr[1]) return 0;

    // Check for last element
    if(arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1;
    int high = n - 2;

    while(low <= high) {
        int mid = (low + high) / 2;

        // if the mid element is itself peak
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return mid;

        // increasing curve, so eleminate the left half
        else if(arr[mid] > arr[mid - 1]) low = mid + 1;

        // decreasing curve, eleminate the right half
        else high = mid - 1;
    }
    return -1;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << PeakElement(arr, n) << endl;
}
