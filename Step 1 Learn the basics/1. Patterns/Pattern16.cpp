#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    char ch = 'A';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}
