#include<bits/stdc++.h>
using namespace std;
int Floor(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int Ceil(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] >= target) {
            ans = arr[mid];
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

    cout << "Floor: " << Floor(arr, n, target) << endl;
    cout << "Ceil: " << Ceil(arr, n, target) << endl;
}
