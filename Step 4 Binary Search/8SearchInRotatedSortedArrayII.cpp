#include<bits/stdc++.h>
using namespace std;
bool SearchInRotatedSortedArray(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) return true;

        else if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        //Left Sorted
        else if(arr[low] <= arr[mid]) {

            //If element lies in the left half
            if(arr[low] <= target && target <= arr[mid]) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        //Right Sorted
        else {
            if(arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
    }
    return false;
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

    if(SearchInRotatedSortedArray(arr, n, target)) {
        cout << "Found" << endl;
    }
    else cout << "Not Found" << endl;
}
