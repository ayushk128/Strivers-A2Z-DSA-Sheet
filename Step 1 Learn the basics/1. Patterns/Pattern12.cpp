#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            cout << j + 1;
        }
        for(int j = 0; j<2 * (n - i - 1); j++) {
            cout << " ";
        }

        for(int j = i + 1; j>=1; j--) {
            cout << j;
        }
        cout << endl;
    }
}
