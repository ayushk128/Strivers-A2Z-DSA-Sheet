#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    // Precompute
    // map<char, int> mpp;
    unordered_map<char, int> mpp;
    for(int i = 0; i<s.size(); i++) {
        mpp[s[i]]++;
    }

    int q;
    cin >> q;

    for(auto it : mpp) {
        cout << it.first << "-->" << it.second << endl;
    }
    while(q--) {
        char ch;
        cin >> ch;

        // Fetch
        cout << mpp[ch] << endl;
    }
}