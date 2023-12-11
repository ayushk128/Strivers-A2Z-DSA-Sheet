// Revisit it
#include<bits/stdc++.h>
using namespace std;
long long Multiply(float n, float value) {

    // cout <<"Power Value: " <<  (long long)pow(value, n) << endl;
    return (long long)pow(value, n);
}
int NthRoot(int n, int value) {
    int low = 1;
    int high = value;
    int ans = -1;

    while(low <= high) {
        long long mid = (low + high) / 2;

        if(Multiply(n, mid) == value) {
            return mid;
        }
        else if(Multiply(n, mid) < value) {
            low = mid + 1;
            // cout << "Low: " << low << endl;
        }
        else {
            high = mid - 1;
            // cout << "High: " << high << endl;
        } 
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    int n;
    cin >> n;
    cin >> value;
    
    cout << NthRoot(n, value) << endl;
}
