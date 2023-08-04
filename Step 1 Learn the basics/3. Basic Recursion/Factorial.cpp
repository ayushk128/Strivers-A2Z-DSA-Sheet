#include<bits/stdc++.h>
using namespace std;
int factorial(int n) {
    if(n == 1) return 1;

    return n * factorial(n - 1);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    cout << factorial(n) << endl;
}