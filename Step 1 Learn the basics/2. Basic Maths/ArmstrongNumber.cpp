#include<bits/stdc++.h>
using namespace std;
int countDigits(int n) {
    int count = 0;

    while(n > 0) {
        count++;
        n /= 10;
    }

    return count;
}
bool ArmstrongNumber(int n) {
    int count = countDigits(n);

    int storedNumber = n;
    int sum = 0;
    while(n > 0) {
        int rem = n % 10;
        // cout << "Current Remainder: " << rem << endl;
        double temp = pow(rem, count);
        // cout << "Current remainder raised to power of count of digits: " <<  temp << endl;
        sum += temp;
        // cout << "Current Sum: " << sum << endl;
        n /= 10;
    }
    if(sum == storedNumber)
        return true;
    
    return false;

}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    if(ArmstrongNumber(n))
        cout << "Armstrong Number" << endl;
    else 
        cout << "Not Armstrong Number" << endl;
}