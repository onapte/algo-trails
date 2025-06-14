#include <bits/stdc++.h>
using namespace std;

// Recursion
// T: O(n^n), S: O(n) -> call stack
int solve(vector<int> &prices, int n)
{
    if (n == 0)
        return 0;

    int ans = prices[n];
    for (int k = 1; k < n; k++)
    {
        ans = max(ans, prices[k] + solve(prices, n - k));
    }

    return ans;
}

// Recursion + Memo
// T: O(n^2), S: O(n) + O(n) -> call stack
int solve(vector<int> &prices, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = prices[n];
    for (int k = 1; k < n; k++)
    {
        ans = max(ans, prices[k] + solve(prices, n - k));
    }

    dp[n] = ans;
    return dp[n];
}

// Tabulation
// T: O(n^2), S: O(n)
int solve(vector<int> &prices)
{
    int n = prices.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int ans = prices[i - 1];
        for (int j = 1; j < i; j++)
        {
            ans = max(ans, prices[j - 1] + dp[i - j]);
        }

        dp[i] = ans;
    }

    return dp[n];
}