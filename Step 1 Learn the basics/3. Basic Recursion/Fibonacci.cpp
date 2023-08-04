#include<bits/stdc++.h>
using namespace std;
int Fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    int last = Fibonacci(n - 1);
    int sLast = Fibonacci(n - 2);

    return last + sLast;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << Fibonacci(n) << endl;
}