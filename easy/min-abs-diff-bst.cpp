#include <bits/stdc++.h>
using namespace std;

// T: O(n), S: O(1) + O(h) -> call stack
void solve(TreeNode *node, int &prev, int &ans)
{
    if (node == nullptr)
        return;

    solve(node->left, prev, ans);

    if (prev == -1)
        prev = node->val;
    else
    {
        ans = min(ans, abs(prev - node->val));
        prev = node->val;
    }

    solve(node->right, prev, ans);
}