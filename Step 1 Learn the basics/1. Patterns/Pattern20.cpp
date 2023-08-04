#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int spaces = 2 * (n - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j<=i; j++) {
            cout << "*";
        }
        for(int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for(int j = 0; j<=i; j++) {
            cout << "*";
        }

        spaces-=2;
        cout << endl;
    }
    spaces = 2;
    for(int i = 0; i<n - 1; i++) {
        for(int j = 0; j<n - i - 1; j++) {
            cout << "*";
        }
        for(int j = 0; j<spaces; j++) {
            cout << " ";
        }
        spaces+=2;

        for(int j = 0; j < n-i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}