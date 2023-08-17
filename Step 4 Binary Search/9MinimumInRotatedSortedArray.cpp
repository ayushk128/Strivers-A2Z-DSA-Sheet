#include<bits/stdc++.h>
using namespace std;
int MinimumInRotatedSortedArray(int *arr, int n) {
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;

        // Left half is sorted
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int MinimumInRotatedSortedArrayOptimized(int *arr, int n) {
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;

        // Entire array is sorted
		if(arr[low] <= arr[high]) {
			ans = min(ans, arr[low]);
			break;
		}

        // Left half is sorted
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
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

    cout << MinimumInRotatedSortedArray(arr, n) << endl;
    cout << MinimumInRotatedSortedArrayOptimized(arr, n) << endl;
}
