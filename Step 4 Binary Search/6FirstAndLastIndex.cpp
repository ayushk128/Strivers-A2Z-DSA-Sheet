#include<bits/stdc++.h>
using namespace std;
int LowerBoundIterative(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int UpperBoundIterative(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = n;

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

    pair<int, int> ans;

    int lowerBound = LowerBoundIterative(arr, n, target);
    if(lowerBound == n || arr[lowerBound] != target) {
        ans = make_pair(-1, -1);
    }
    else {
        ans = make_pair(lowerBound, UpperBoundIterative(arr, n, target) - 1);
    }
    
    cout << "First Index: " << ans.first << endl;
    cout << "Last Index: " << ans.second << endl;
}
