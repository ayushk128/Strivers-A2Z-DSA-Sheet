#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int cnt = 1;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n - i - 1; j++) {
            cout << " ";
        }

        for(int j = 0; j<cnt; j++) {
            cout << "*";
        }

        for(int j = 0; j<n - i - 1; j++) {
            cout<<" ";
        }
        cnt+=2;

        cout<<endl;
    }
}
