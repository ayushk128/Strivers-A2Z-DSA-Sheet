#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }
}