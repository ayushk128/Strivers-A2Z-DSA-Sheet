#include<bits/stdc++.h>
using namespace std;
bool PalindromeCheck(int i, string str) {
    if(i >= str.length() / 2)
        return true;
    if(str[i] != str[str.length() - i - 1])
        return false;
    PalindromeCheck(i + 1, str);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    cin >> str;

    if(PalindromeCheck(0, str))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}