#include <bits/stdc++.h>
using namespace std;

int numberOfDays(vector<int> weights, int weight) {
    int loads = 0;
    int noOfDays = 1;
    for(int i = 0; i<weights.size(); i++) {
        if(loads + weights[i] <= weight) {
            loads += weights[i];
            
        }
        else {
            loads = weights[i];
            noOfDays++;
        }
    }
    return noOfDays; 
}
int leastWeightCapacity(vector<int>& nums, int days) {

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(numberOfDays(nums, mid) <= days) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    cout << leastWeightCapacity(arr, d) << endl;
}