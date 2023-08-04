#include<bits/stdc++.h>
using namespace std;
void sumN(int i, int sum) {
    if(i == 0) {
        cout << sum << endl;
        return;
    }
    sum = sum + i;
    sumN(i - 1, sum);
}
int sumNAlternate(int n) {
    if(n == 1) return 1;
    return n + sumNAlternate(n - 1);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;
    sumN(n, 0);
    cout << "------------" << endl;
    cout << sumNAlternate(n) << endl;
}