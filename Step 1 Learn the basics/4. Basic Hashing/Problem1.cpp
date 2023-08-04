#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    // Precompute, considering maximum number in the array is 12
    int hash[13] = {0};
    for(int i = 0; i<n; i++) {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;

    while(q--) {
        int number;
        cin >> number;

        // Fetch
        cout << hash[number] << endl;
    }
}