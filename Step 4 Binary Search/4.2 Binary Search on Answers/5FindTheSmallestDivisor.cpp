#include <bits/stdc++.h>
using namespace std;
int findSum(vector<int>& nums, int divisor) {
    int sum = 0;
    for(int i = 0; i<nums.size(); i++) {
        sum += ceil((double)nums[i]/(double)divisor);
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(findSum(nums, mid) <= threshold) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
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

    int threshold;
    cin >> threshold;

    cout << smallestDivisor(arr, threshold) << endl;
}