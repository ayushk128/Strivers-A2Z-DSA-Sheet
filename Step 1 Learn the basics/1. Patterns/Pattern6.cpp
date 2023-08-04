#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++) {
        for(int j = 1; j<= n - i; j++) {
            cout << j << " ";
        }
        cout<<endl;
    }
}
