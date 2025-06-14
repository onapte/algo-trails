#include <bits/stdc++.h>
using namespace std;

// Recursion
// T: O(k^n), S: O(n) -> call stack
int solve(vector<int> &arr, int i, int k, int n)
{
    if (i >= n)
        return 0;

    int maxi = -1, ans = 0, len = 0;
    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = maxi * len + solve(arr, j + 1, k, n);
        ans = max(ans, sum);
    }

    return ans;
}

// Recursion + Memo
// T: O(n * k), S: O(n) + O(n) -> call stack
int solve(vector<int> &arr, int i, int k, int n, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        dp[i];

    int maxi = -1, ans = 0, len = 0;
    for (int j = i; j < min(i + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = maxi * len + solve(arr, j + 1, k, n, dp);
        ans = max(ans, sum);
    }

    dp[i] = ans;
    return dp[i];
}

// Tabulation
// T: O(n * k), S: O(n)
int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for (int i = n-1; i >= 0; i--) {
            int maxi = -1, len = 0, ans = 0;
            for (int j = i; j < min(i+k, n); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = maxi * len + dp[j+1];
                ans = max(sum, ans);
            }
            dp[i] = ans;
        }

        return dp[0];
    }