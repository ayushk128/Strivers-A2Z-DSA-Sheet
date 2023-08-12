#include<bits/stdc++.h>
using namespace std;
int SearchInsertPosition(int *arr, int n, int target) {
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

    cout << SearchInsertPosition(arr, n, target) << endl;
}
