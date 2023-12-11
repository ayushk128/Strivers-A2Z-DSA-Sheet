#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int>& arr, int mid){
    long long int total = 0;
    for(int i=0; i<arr.size(); i++){
        int y = ceil( arr[i] / (double)mid );
        total += y;
    }
    return total;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here

        int n = v.size();
        int start = 1;
        int end = findMax(v);

        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            long long int hours = calculateTotalHours(v,mid);

            if(hours <= h){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return start;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    long long h;
    cin >> h;
    cout << minimumRateToEatBananas(arr, h) << endl;
}
