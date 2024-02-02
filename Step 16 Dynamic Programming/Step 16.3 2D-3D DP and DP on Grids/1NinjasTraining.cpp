#include <bits/stdc++.h>
using namespace std;
int ninjasTrainingRecursive(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + ninjasTrainingRecursive(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int ninjasTrainingMemoization(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(dp[day][last] != -1) 
        return dp[day][last];

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + ninjasTrainingMemoization(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjasTrainingTabulation(int days, vector<vector<int>> &points)
{
    vector<vector<int>> dp(days, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day<days; day++) {
        for(int last = 0; last<4; last++) {
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[days - 1][3];
}

int ninjasTraining(vector<vector<int>> points)
{
    int days = points.size();

    // return ninjasTrainingRecursive(days - 1, 3, points);

    // vector<vector<int>> dp(days, vector<int>(4, -1));
    // return ninjasTrainingMemoization(days - 1, 3, points, dp);

    return ninjasTrainingTabulation(days, points);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    cout << ninjasTraining(points) << endl;
}