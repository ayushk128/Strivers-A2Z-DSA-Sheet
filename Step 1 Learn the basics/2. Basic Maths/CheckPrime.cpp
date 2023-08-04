#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int n) {
    int count = 0;
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    if(checkPrime(n)) cout << "Prime Number" << endl;
    else cout << "Not Prime Number" << endl;
}