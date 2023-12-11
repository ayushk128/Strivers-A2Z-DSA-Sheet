#include<bits/stdc++.h>
using namespace std;

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

    int fIndex = FirstIndex(arr, n, target);
    if(fIndex == -1) {
        cout << "Number of Occurrences: " << 0 << endl;
    }

    cout << LastIndex(arr, n, target) - fIndex + 1 << endl;

}
