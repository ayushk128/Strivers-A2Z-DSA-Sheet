#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++) {
        for(char ch = 65 + n - i - 1; ch <= 65 + n - 1; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}