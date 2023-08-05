#include<bits/stdc++.h>
using namespace std;
void SelectionSort(vector<int> &arr, int n) {
    for(int i = 0; i<n-1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }                                                                             
        }
        swap(arr[i], arr[minIndex]);
        // cout << "After iteration " << i << ": ";

        // for(int i = 0; i<n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
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

    SelectionSort(arr, n);

    cout << "After Sorting: ";
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
}