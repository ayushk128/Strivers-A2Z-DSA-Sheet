#include<bits/stdc++.h>
using namespace std;
void printFromNto1(int n) {
    if(n == 0)
        return;
    cout << n << endl;
    printFromNto1(n - 1);
}
void printFromNto1(int i, int n) {
    if(i > n)
        return;

    printFromNto1(i + 1, n);
    cout << i << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;
    printFromNto1(n);
    cout <<"-------------"<< endl;
    printFromNto1(1, n);
}