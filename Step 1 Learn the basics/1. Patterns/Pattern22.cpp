#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for(int i = 0; i < 2*n - 1; i++) {
        for(int j = 0; j < 2*n - 1; j++) {
            int topDistance = i;
            int leftDistance = j;
            int bottomDistance = (2 * n - 2) - i;
            int rightDistance = (2 * n - 2) - j;

            cout << n - min(min(topDistance, bottomDistance), min(leftDistance, rightDistance));
        }
        cout << endl;
    }
}