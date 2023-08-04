#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    int space = 2 * n - 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "*";
        }
        for(int j = 0; j<space; j++) {
            cout << " ";
        }
        for(int j = 0; j<=i; j++) {
            cout << "*";
        }
        space-=2;
        cout << endl;
    }
}