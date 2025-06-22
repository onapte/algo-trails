#include <bits/stdc++.h>
using namespace std;

// Naive solution
// T: O(n), S: O(n)
bool isPalindrome(string s)
{
    string s2("");

    for (char c : s)
    {
        if (isalnum(c))
            s2.push_back(tolower(c));
    }

    int len = s2.length();
    int i = 0, j = len - 1;

    while (i <= j)
    {
        if (s2[i] != s2[j])
            return false;
        j--;
        i++;
    }

    return true;
}

// Optimized
// T: O(n), S: O(1)
bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;

    while (i <= j)
    {
        while (i < j && !isalnum(s[i]))
            i++;
        while (j > i && !isalnum(s[j]))
            j--;

        if (i > j)
            break;

        if (tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }

    return true;
}