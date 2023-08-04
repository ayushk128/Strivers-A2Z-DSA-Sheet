#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int gcd;
    for(int i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// Little bit optimization
int gcd2(int a, int b) {
    int gcd;
    for(int i = min(a, b); i >= 1; i--) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }
    return gcd;
}
int EuclideanGCD(int a, int b) {
    if(b == 0)
        return a;
    return EuclideanGCD(b, a%b);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
    cout << gcd2(a, b) << endl;
    cout << EuclideanGCD(a, b) << endl;
}