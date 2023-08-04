#include<bits/stdc++.h>
using namespace std;
int countDigits1(int n) {
    int count = 0;

    while(n > 0) {
        count++;
        n /= 10;
    }

    return count;
}

int countDigits2(int n) {
    string s = to_string(n);

    return s.length();
}

int countDigits3(int n) {
    int count = (int)log10(n) + 1;

    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    cout << countDigits1(n) << endl;
    cout << countDigits2(n) << endl;
    cout << countDigits3(n) << endl;
}