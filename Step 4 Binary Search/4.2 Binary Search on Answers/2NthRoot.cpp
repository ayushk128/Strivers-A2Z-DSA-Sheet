#include<bits/stdc++.h>
using namespace std;
// return 1 if == mid
// return 0 if < mid
// return 2 if > mid
int func(int mid, int n, int val) {
    long long ans = 1;
    for(int i = 1; i<=n; i++) {
        ans = ans * mid;
        if(ans > val) return 2;
    }
    if(ans == val) return 1;
    return 0;
}

int NthRoot(int n, int value) {
    int low = 1;
    int high = value;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, value);
        if(midN == 1) {
            return mid;
        }
        else if(midN == 0) {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return -1;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    int n;
    cin >> n;
    cin >> value;
    
    cout << NthRoot(n, value) << endl;
}