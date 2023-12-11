#include<bits/stdc++.h>
using namespace std;
int Sqrt(int value) {
    int low = 1;
    int high = value;
    int ans = 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if((mid * mid) <= value) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // You can also return high.
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    cout << Sqrt(value) << endl;
}
