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

// First Index using only plane Binary search
int FirstIndex(int *arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int first = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == x) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else low = mid + 1;
    }
    return first;
}

// Last Index using only plane Binary search
int LastIndex(int *arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int last = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == x) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else low = mid + 1;
    }
    return last;
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

    cout << "-----------------"<<endl;

    int fIndex = FirstIndex(arr, n, target);
    if(fIndex == -1) {
        cout << "First Index: " << fIndex << endl;
        cout << "Last Index: " << -1 << endl;
    }
    else {
        cout << "First Index: " << fIndex << endl;
        cout << "Last Index: " << LastIndex(arr, n, target) << endl;
    }
}
