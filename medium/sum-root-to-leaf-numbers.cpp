#include <bits/stdc++.h>
using namespace std;

// DFS: Tail recursion-like behavior
// T: O(n), S: O(1) + O(n) -> Recursion stack
void solve(TreeNode *node, int &sum, int tempSum)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        sum += (tempSum * 10) + node->val;
        return;
    }

    solve(node->left, sum, (tempSum * 10) + node->val);
    solve(node->right, sum, (tempSum * 10) + node->val);
}
