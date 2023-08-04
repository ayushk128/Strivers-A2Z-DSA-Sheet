#include<bits/stdc++.h>
using namespace std;
void printDivisors(int n) {
    for(int i = 1; i<=n; i++) {
        if(n % i == 0) {
            cout << i <<" ";
        }
    }
}
void printDivisorsOptimal(int n) {
    vector<int> divisors;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            // cout << i <<" ";
            divisors.emplace_back(i);
            if(i != n/i) {
                divisors.emplace_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for(auto elements : divisors) {
        cout << elements <<" ";
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    printDivisorsOptimal(n);
}