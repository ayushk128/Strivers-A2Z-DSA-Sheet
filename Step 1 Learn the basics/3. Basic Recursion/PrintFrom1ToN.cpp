#include<bits/stdc++.h>
using namespace std;
void printFrom1ToN(int n) {
    if(n == 0) return;

    printFrom1ToN(n - 1);
    cout << n << endl;
}

void printFrom1ToN(int i, int n) {
    if(i > n) return;
    cout << i << endl;
    printFrom1ToN(i + 1, n);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    printFrom1ToN(n);
    cout <<"---------------" << endl;
    printFrom1ToN(1, n);
}