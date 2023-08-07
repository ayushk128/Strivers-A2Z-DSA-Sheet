#include<bits/stdc++.h>
using namespace std;
int UpperBoundIterative(int *arr, int low, int high, int target) {
    int ans = high + 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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

    int target;
    cin >> target;

    cout << UpperBoundIterative(arr, 0, n - 1, target);
}