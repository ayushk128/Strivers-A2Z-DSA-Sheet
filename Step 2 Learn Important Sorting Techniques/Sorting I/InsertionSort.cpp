#include<bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            j--;
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

    InsertionSort(arr, n);

    cout << "After Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
}