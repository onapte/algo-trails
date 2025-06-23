#include <bits/stdc++.h>
using namespace std;

// T: O(n), S: O(1) + O(h) -> call stack
void solve(TreeNode *node, int k, int &ans, int &idx)
{
    if (node == nullptr)
        return;

    solve(node->left, k, ans, idx);

    idx++;
    if (idx == k)
    {
        ans = node->val;
        return;
    }

    solve(node->right, k, ans, idx);
}