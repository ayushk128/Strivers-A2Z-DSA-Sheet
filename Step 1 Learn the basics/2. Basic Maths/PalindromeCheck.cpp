#include<bits/stdc++.h>
using namespace std;
int reverseNumber(int n) {
    int number = 0;

    while(n > 0) {
        int lastDigit = n % 10;
        number = number * 10 + lastDigit;

        n /= 10;
    }
    return number;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    if(reverseNumber(n) == n) {
        cout <<"Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }
}