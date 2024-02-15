#include <bits/stdc++.h>
using namespace std;
int EditDistanceRecursive(int i, int j, string &s, string &t) {
    // Base case
    if(i < 0) return j + 1;  //If s is exhausted, we have to inster j + 1 letters
    if(j < 0) return i + 1;  //If t is exhausted, we have to inster i + 1 letters


    // Match
    if(s[i] == t[j]) return EditDistanceRecursive(i - 1, j - 1, s, t);

    // Not Match case
    int insert = 1 + EditDistanceRecursive(i, j - 1, s, t);  //Hypothetically inserting at index i + 1;
    int del = 1 + EditDistanceRecursive(i - 1, j, s, t); //Deleting the letter at index i
    int replace = 1 + EditDistanceRecursive(i - 1, j - 1, s, t); // Replacing the character at index i;

    return min(insert, min(del, replace));

}
int EditDistanceMemoization(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    // Base case
    if(i < 0) return j + 1;  //If s is exhausted, we have to inster j + 1 letters
    if(j < 0) return i + 1;  //If t is exhausted, we have to inster i + 1 letters

    if(dp[i][j] != -1) return dp[i][j];
    // Match
    if(s[i] == t[j]) return dp[i][j] = EditDistanceMemoization(i - 1, j - 1, s, t, dp);

    // Not Match case
    int insert = 1 + EditDistanceMemoization(i, j - 1, s, t, dp);  //Hypothetically inserting at index i + 1;
    int del = 1 + EditDistanceMemoization(i - 1, j, s, t, dp); //Deleting the letter at index i
    int replace = 1 + EditDistanceMemoization(i - 1, j - 1, s, t, dp); // Replacing the character at index i;

    return dp[i][j] = min(insert, min(del, replace));

}

int EditDistanceMemoizationShiftedIndex(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    // Base case
    if(i == 0) return j;  //If s is exhausted, we have to inster j + 1 letters
    if(j == 0) return i;  //If t is exhausted, we have to inster i + 1 letters

    if(dp[i][j] != -1) return dp[i][j];
    // Match
    if(s[i - 1] == t[j - 1]) return dp[i][j] = EditDistanceMemoizationShiftedIndex(i - 1, j - 1, s, t, dp);

    // Not Match case
    int insert = 1 + EditDistanceMemoizationShiftedIndex(i, j - 1, s, t, dp);  //Hypothetically inserting at index i + 1;
    int del = 1 + EditDistanceMemoizationShiftedIndex(i - 1, j, s, t, dp); //Deleting the letter at index i
    int replace = 1 + EditDistanceMemoizationShiftedIndex(i - 1, j - 1, s, t, dp); // Replacing the character at index i;

    return dp[i][j] = min(insert, min(del, replace));

}

int EditDistanceTabulation(string &s, string &t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // Base case
    for(int i = 0; i<=n; i++) dp[i][0] = i;
    for(int j = 0; j<=m; j++) dp[0][j] = j; 
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                // Not Match case
                int insert = 1 + dp[i][j - 1];  //Hypothetically inserting at index i + 1;
                int del = 1 + dp[i - 1][j]; //Deleting the letter at index i
                int replace = 1 + dp[i - 1][j - 1]; // Replacing the character at index i;

                dp[i][j] = min(insert, min(del, replace));
            }
        }
    }
    return dp[n][m];

}
int EditDistanceSpaceOptimization(string &s, string &t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    // Base case
    for(int j = 0; j<=m; j++) prev[j] = j; 
    
    for(int i = 1; i<=n; i++) {
        curr[0] = i;
        for(int j = 1; j<=m; j++) {
            if(s[i - 1] == t[j - 1]) curr[j] = prev[j - 1];
            else {
                // Not Match case
                int insert = 1 + curr[j - 1];  //Hypothetically inserting at index i + 1;
                int del = 1 + prev[j]; //Deleting the letter at index i
                int replace = 1 + prev[j - 1]; // Replacing the character at index i;

                curr[j] = min(insert, min(del, replace));
            }
            prev = curr;
        }
    }
    return prev[m];

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string t;
    cin >> t;

    int n = s.size();
    int m = t.size();

    cout << EditDistanceRecursive(n - 1, m - 1, s, t) << endl;

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << EditDistanceMemoization(n - 1, m - 1, s, t, dp) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << EditDistanceMemoizationShiftedIndex(n, m, s, t, dp) << endl;

    cout << EditDistanceTabulation(s, t) << endl;
    cout << EditDistanceSpaceOptimization(s, t) << endl;
}