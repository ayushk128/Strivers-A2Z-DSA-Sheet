#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char ch;
        for(int j = 0; j< n - i - 1; j++) {
            cout << "  ";
        }

        for(ch = 'A'; ch <= 65 + i; ch++) {
            cout << ch <<" ";
        }
        // cout << ch;
        ch -= 2;
        for(char ch2 = ch; ch2 >= 65; ch2--) {
            cout << ch2 << " ";
        }
        cout << endl;
    }
}