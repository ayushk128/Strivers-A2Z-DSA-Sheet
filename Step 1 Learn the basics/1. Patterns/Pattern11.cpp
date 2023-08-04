#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        if(i % 2 == 0) {
            int print = 1;
            for(int j = 0; j<=i; j++) {
                cout << print << " ";
                print = 1 - print; 
            }
        }
        else {
            int print = 0;
            for(int j = 0; j<=i; j++) {
                cout << print << " ";
                print = 1 - print; 
            }
        }
        cout << endl;
    }
}
