#include<bits/stdc++.h>
using namespace std;
int BinarySerachIterative(int *arr, int low, int high, int target) {

    while(low <= high) {
        int mid = low + (high - low) / 2;
        // int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        else if(target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int BinarySerachRecursive(int *arr, int low, int high, int target) {
    if(low > high) return -1;
    long long mid = low + (high - low) / 2;

    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return BinarySerachRecursive(arr, mid + 1, high, target);
    else return BinarySerachRecursive(arr, low, mid - 1, target);
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

    cout << BinarySerachIterative(arr, 0, n - 1, target) << endl;
    cout << BinarySerachRecursive(arr, 0, n - 1, target) << endl;
}