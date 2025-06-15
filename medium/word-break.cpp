#include <bits/stdc++.h>
using namespace std;

// Recursion
// T: O(2^n), S: O(n) -> call stack
bool solve(string &s, unordered_set<string> &words, int i)
{
    if (i == s.length())
        return true;

    bool ans = false;
    string temp("");

    for (int k = i; k < s.length(); k++)
    {
        temp.push_back(s[k]);
        if (words.count(temp))
            ans = ans || solve(s, words, k + 1);
    }

    return ans;
}

// Recursion + memo
// T: O(n^2), S: O(n) + O(n) -> call stack
bool solve(string &s, unordered_set<string> &words, int i, vector<int> &dp)
{
    if (i == s.length())
        return true;
    if (dp[i] != -1)
        return dp[i];

    bool ans = false;
    string temp("");

    for (int k = i; k < s.length(); k++)
    {
        temp.push_back(s[k]);
        if (words.count(temp))
            ans = ans || solve(s, words, k + 1, dp);
    }

    dp[i] = ans;
    return dp[i];
}

// Tabulation
// T: O(n^3), S: O(n)
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    unordered_set<string> words(wordDict.begin(), wordDict.end());

    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        bool ans = false;

        for (int k = i + 1; k <= n; k++)
        {
            if (words.count(s.substr(i, k - i)) && dp[k])
            {
                ans = true;
                break;
            }
        }

        dp[i] = ans;
    }

    return dp[0];
}