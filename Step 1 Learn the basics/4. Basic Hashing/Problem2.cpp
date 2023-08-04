#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    // Precompute
    // int hash[26] = {0}; //If it contains only lower case
    int hash[256] = {0}; //If it contains all characters
    for(int i = 0; i<s.size(); i++) {
        // hash[s[i] - 'a']++; //If it contains only lower case
        hash[s[i]]++; //If it contains all characters
    }

    int q;
    cin >> q;

    while(q--) {
        char ch;
        cin >> ch;

        // Fetch
        // cout << hash[ch - 'a'] << endl;  //If it contains only lower case
        cout << hash[ch] << endl; //If it contains all characters
    }
}