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
    // Precompute, by hashing
    // map<int, int> mpp;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    
    for(auto it : mpp) {
        cout << it.first << "-->" << it.second << endl;
    }

    int q;
    cin >> q;

    while(q--) {
        int number;
        cin >> number;

        // Fetch
        cout << mpp[number] << endl;
    }
}