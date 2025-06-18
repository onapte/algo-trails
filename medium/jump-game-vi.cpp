#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(vector<int> &nums, int i, int k, int n)
{
    if (i == n)
        return 0;
    if (i == n - 1)
        return nums[i];

    int sum = INT_MIN;
    for (int j = i + 1; j <= min(n - 1, i + k); j++)
    {
        sum = max(sum, nums[i] + solve(nums, j, k, n));
    }

    return sum;
}

// Recursion + memo
int solve(vector<int> &nums, int i, int k, int n, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (i == n - 1)
        return nums[i];
    if (dp[i] != INT_MIN)
        return dp[i];

    int sum = INT_MIN;
    for (int j = i + 1; j <= min(n - 1, i + k); j++)
    {
        sum = max(sum, nums[i] + solve(nums, j, k, n, dp));
    }

    return dp[i] = sum;
}

// Tabulation
int maxResult(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, INT_MIN);
    dp[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int sum = INT_MIN;
        for (int j = i + 1; j <= min(n - 1, i + k); j++)
        {
            sum = max(sum, dp[j]);
        }

        dp[i] = sum + nums[i];
    }

    return dp[0];
}