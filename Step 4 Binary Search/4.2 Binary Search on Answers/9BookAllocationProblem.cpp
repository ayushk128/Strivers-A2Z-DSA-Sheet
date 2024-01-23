#include <bits/stdc++.h>
using namespace std;

int noOfStudents(vector<int> &arr, int pages) {
    int students = 1;
    long long noOfPages = 0;
    for(int i = 0; i<arr.size(); i++) {
        if(noOfPages + arr[i] <= pages) {
            noOfPages += arr[i];
        }
        else {
            noOfPages = arr[i];
            students++;
        }
    }
    return students;
}
int numberOfPages(vector<int> &arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(noOfStudents(arr, mid) > m) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return low;
} 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    cout << numberOfPages(arr, n, m) << endl;
}