#include<bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &arr, int n) {
    for(int i = n - 1; i>=1; i--) {
        for(int j = 0; j<=i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void BubbleSortOptimized(vector<int> &arr, int n) {
    for(int i = n - 1; i>=1; i--) {
        int didSwap = 0;
        for(int j = 0; j<=i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) {
            break;
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Before Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] <<" ";
    }
    cout << endl;

    BubbleSortOptimized(arr, n);

    cout << "After Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
}