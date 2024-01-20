#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &bloomDay, int day, int k, int m)
{
    int noOfBoquets = 0;
    int cnt = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfBoquets += (cnt / k);
            cnt = 0;
        }
    }

    noOfBoquets += (cnt / k);

    return noOfBoquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long noOfFlowers = m * 1ll * k * 1ll;

    if (n < noOfFlowers)
        return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(bloomDay, mid, k, m))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
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

    // Adjacent flowers
    int k;
    cin >> k;

    // number of boquets
    int m;
    cin >> m;

    cout << minDays(arr, m, k) << endl;
}