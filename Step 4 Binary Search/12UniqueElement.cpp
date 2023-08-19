#include<bits/stdc++.h>
using namespace std;
int UniqueElement(int *arr, int n) {
    // Single Element
    if(n == 1) return arr[0];

    // First element is unique
    if(arr[0] != arr[1]) return arr[0];

    // Last element is unique
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        // We found our unique element
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];

        // same element at (even, odd) index, eleminat the left half
        if(((mid % 2 == 0) && (arr[mid] == arr[mid + 1])) 
            || ((mid % 2 == 1) && (arr[mid] == arr[mid - 1]))) {
                low = mid + 1;
        }

        // same element at (odd, even) index, eleminat the right half
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
    cout << UniqueElement(arr, n) << endl;
}
